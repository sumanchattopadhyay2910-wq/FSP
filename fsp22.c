// convert decimal number to binary number using stack.
#include <stdio.h>
#include <stdlib.h>
#define MAX 32

typedef struct {
    int data[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int num) {
    if (!isFull(s)) {
        s->top++;
        s->data[s->top] = num;
    }
}

int pop(Stack *s) {
    if (!isEmpty(s)) {
        int num = s->data[s->top];
        s->top--;
        return num;
    }
    return -1; // Return -1 if stack is empty
}

void decimalToBinary(int decimal) {
    Stack s;
    initStack(&s);
    
    // Convert decimal to binary and push onto stack
    while (decimal > 0) {
        push(&s, decimal % 2);
        decimal /= 2;
    }
    
    // Pop from stack to get binary representation
    printf("Binary representation: ");
    while (!isEmpty(&s)) {
        printf("%d", pop(&s));
    }
    printf("\n");
}

int main() {
    int decimal;
    
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    
    if (decimal < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1;
    }
    
    decimalToBinary(decimal);
    
    return 0;
}
