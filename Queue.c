#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
struct Queue {
    int arr[MAX_SIZE];
    int front, rear;
};
void initialize(struct Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}
int isEmpty(struct Queue *queue) {
    return queue->front == -1;
}
int isFull(struct Queue *queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}
void enqueue(struct Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue overflow: Cannot enqueue element %d\n", value);
        return;
    }
    
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->arr[queue->rear] = value;
}
int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow: Cannot dequeue element\n");
        return -1;
    }
    
    int value = queue->arr[queue->front];
    
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    
    return value;
}
void display(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    
    int current = queue->front;
    printf("Queue elements: ");
    
    while (current != queue->rear) {
        printf("%d ", queue->arr[current]);
        current = (current + 1) % MAX_SIZE;
    }
    printf("%d\n", queue->arr[current]);
}

int main() {
    struct Queue queue;
    initialize(&queue);
    enqueue(&queue, 10);
    enqueue(&queue, 40);
    enqueue(&queue, 30);
    display(&queue);
    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Dequeued element: %d\n", dequeue(&queue));
    display(&queue);   
    return 0;
}

