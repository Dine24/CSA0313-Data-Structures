#include <stdio.h>    
#include <stdlib.h>  

int main() {  
    int n, a[100], i;

    printf("Enter the size of list=");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        
      }
	for(i=0;i<n;i++){
	
    if(a[i] % 2 == 0) {
        printf("%d is an Even number.\n", a[i]);
        } 
	else {
        printf("%d is an Odd number.\n", a[i]);
    }
}
    return 0;
}

