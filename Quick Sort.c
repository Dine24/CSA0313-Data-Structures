#include <stdio.h>
#include <stdlib.h>
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
int main() {
    int arr[100],n,i;
    printf("Enter the size of Array=");
    scanf("%d",&n);
    printf("Enter the elements=");
    for(i=0;i<n;i++){
    	scanf("%d",&arr[i]);
	}
    qsort(arr, n, sizeof(int), compare);
    for (i = 0; i < n; i++)
        printf("%d", arr[i]);
    return 0;
}

