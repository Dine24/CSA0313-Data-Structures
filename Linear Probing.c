#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10  
int hashTable[TABLE_SIZE];
void initializeTable() {
	int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }
}
int hashFunction(int key) {
    return key % TABLE_SIZE;
}
void insert(int key) {
    int index = hashFunction(key);
    while (hashTable[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
    }
    hashTable[index] = key;
}
int search(int key) {
    int index = hashFunction(key);
    int startIndex = index;
    while (hashTable[index] != -1) {
        if (hashTable[index] == key) {
            return index;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == startIndex) {
            return -1;
        }
    }
    return -1;
}
void displayTable() {
	int i;
    printf("Hash Table:\n");
    for (i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != -1) {
            printf("Index %d: %d\n", i, hashTable[i]);
        } else {
            printf("Index %d: Empty\n", i);
        }
    }
}

int main() {
    initializeTable();
    insert(23);
    insert(43);
    insert(13);
    insert(27);
    insert(34);
    displayTable();
    int key = 43;
    int position = search(key);
    if (position != -1) {
        printf("\nKey %d found at index %d\n", key, position);
    } else {
        printf("\nKey %d not found in the hash table\n", key);
    }

    return 0;
}

