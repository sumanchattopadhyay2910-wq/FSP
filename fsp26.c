// write a c program of postfix evaluation using stack
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int stack[100];
int top = -1;

void push(int value)
{
    top++;
    stack[top] = value;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    int value = stack[top];
    top--;
    return value;
}

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int evaluatePostfix(char* expression)
{
    int i;
    for (i = 0; expression[i] != '\0'; i++)
    {
        if (isdigit(expression[i]))
        {
            push(expression[i] - '0');
        }
        else if (isOperator(expression[i]))
        {
            int operand2 = pop();
            int operand1 = pop();
            switch (expression[i])
            {
                case '+':
                    push(operand1 + operand2);
                    break;
                case '-':
                    push(operand1 - operand2);
                    break;
                case '*':
                    push(operand1 * operand2);
                    break;
                case '/':
                    push(operand1 / operand2);
                    break;
            }
        }
    }
    return pop();
}

int main()
{
    char expression[100];
    printf("Enter postfix expression: ");
    scanf("%s", expression);
    printf("Result: %d\n", evaluatePostfix(expression));
    return 0;
}