#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
struct Stack {
    int top;
    int items[MAX];
};
void initStack(struct Stack* stack) {
    stack->top = -1;
}
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int value) {
    if (stack->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++stack->top] = value;
}
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->items[stack->top--];
}
int peek(struct Stack* stack) {
    return stack->items[stack->top];
}
int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

void infixToPostfix(char infix[], char postfix[]) {
    struct Stack stack;
    initStack(&stack);
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        char ch = infix[i];
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
      
        else if (ch == '(') {
            push(&stack, ch);
        }
        else if (ch == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack);
        }
    
        else if (isOperator(ch)) {
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(ch)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, ch);
        }
        i++;
    }

    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0';
}
int evaluatePostfix(char postfix[]) {
    struct Stack stack;
    initStack(&stack);
    int i = 0;

    while (postfix[i] != '\0') {
        char ch = postfix[i];
        if (isdigit(ch)) {
            push(&stack, ch - '0'); 
        }
        else if (isOperator(ch)) {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            switch (ch) {
                case '+': push(&stack, operand1 + operand2); break;
                case '-': push(&stack, operand1 - operand2); break;
                case '*': push(&stack, operand1 * operand2); break;
                case '/': push(&stack, operand1 / operand2); break;
                case '^': push(&stack, (int)pow(operand1, operand2)); break;
            }
        }
        i++;
    }
    return pop(&stack);
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression (e.g., 3+5*(2-8)): ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result of evaluation: %d\n", result);

    return 0;
}

