// write a c program reverse a string using stack.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>                             
#define MAX 100

typedef struct {
    char data[MAX];
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

void push(Stack *s, char c) {
    if (!isFull(s)) {
        s->top++;
        s->data[s->top] = c;
    }
}

char pop(Stack *s) {
    if (!isEmpty(s)) {
        char c = s->data[s->top];
        s->top--;
        return c;
    }
    return '\0';
}

void reverseString(char *str) {
    Stack s;
    initStack(&s);
    
    // Push all characters of the string onto the stack
    for (int i = 0; str[i] != '\0'; i++) {
        push(&s, str[i]);
    }
    
    // Pop all characters from the stack and put them back into the string
    for (int i = 0; !isEmpty(&s); i++) {
        str[i] = pop(&s);
    }
}

int main() {
    char str[MAX];
    
    printf("Enter a string: ");
    fgets(str, MAX, stdin);
    
    // Remove newline character if present
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
    
    reverseString(str);
    
    printf("Reversed string: %s\n", str);
    
    return 0;
}