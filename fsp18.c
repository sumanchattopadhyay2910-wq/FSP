// write a c program stack using array.
#include <stdio.h>
#define MAX 100
int stack[MAX];
int top = -1;  

void push(int value) {
    if (top >= MAX - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack[++top] = value;
    printf("%d pushed to stack.\n", value);
} 

void pop() {
    if (top < 0) {
        printf("Stack underflow!\n");
        return;
    }
    printf("%d popped from stack.\n", stack[top--]);
}   

void display() {
    if (top < 0) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
