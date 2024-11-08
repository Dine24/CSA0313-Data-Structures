#include <stdio.h>  
#include <stdlib.h>  

#define SIZE 4  

int top = -1, inp_array[SIZE];  

void push();  
void pop();  
void show();  
void initializeStack();  

int main()  
{  
    int choice;  
    initializeStack();
    while (1)  
    {  
        printf("\nPerform operations on the stack:");  
        printf("\n1. Push the element\n2. Pop the element\n3. Show\n4. End");  
        printf("\n\nEnter your choice: ");  
        scanf("%d", &choice);  
        switch (choice)  
        {  
        case 1:  
            push();  
            break;  
        case 2:  
            pop();  
            break;  
        case 3:  
            show();  
            break;  
        case 4:  
            exit(0);  
        default:  
            printf("\nInvalid choice!!");  
        }  
    }  
}  

void initializeStack()  
{  
    int n, x,i;  
    printf("Enter the number of elements to initialize the stack (max %d): ", SIZE);  
    scanf("%d", &n);  

    if (n > SIZE)  
    {  
        printf("The stack can only hold %d elements. Setting initial elements to %d.\n", SIZE, SIZE);  
        n = SIZE;  
    }  

    for (i = 0; i < n; i++)  
    {  
        printf("Enter element %d: ", i + 1);  
        scanf("%d", &x);  
        top = top + 1;  
        inp_array[top] = x;  
    }  
    printf("Stack initialized with %d elements.\n", n);
}  

void push()  
{  
    int x;  
    if (top == SIZE - 1)  
    {  
        printf("\nOverflow!!");  
    }  
    else  
    {  
        printf("Enter the element to be added onto the stack: ");  
        scanf("%d", &x);  
        top = top + 1;  
        inp_array[top] = x;  
    }  
}  

void pop()  
{  
    if (top == -1)  
    {  
        printf("\nUnderflow!!");  
    }  
    else  
    {  
        printf("\nPopped element: %d", inp_array[top]);  
        top = top - 1;  
    }  
}  

void show()  
{  
    int i;  
    if (top == -1)  
    {  
        printf("\nUnderflow!!");  
    }  
    else  
    {  
        printf("\nElements present in the stack: \n");  
        for (i = top; i >= 0; --i)  
            printf("%d\n", inp_array[i]);  
    }  
}  

