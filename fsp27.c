#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char ch)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    { stack[++top] = ch;    }
}
char pop()
{
    if (top == -1)
    {        return '\0';    }
    else
    {        return stack[top--];    }
}
char peek()
{
    if (top == -1)
    {
        return '\0';
    }
    return stack[top];
}
int precedence(char ch)
{
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;
    return 0;
}
int isOperator(char ch)
{
    if (ch == '+' || ch == '-' ||
        ch == '*' || ch == '/' ||
        ch == '^')
    {
        return 1;
    }
    return 0;
}
void infixToPostfix(char infix[], char postfix[])
{
    int i;
    int j = 0;
    char ch;
    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];
        if (ch == ' ')
        {
            continue;
        }
        if (isalnum(ch))
        {
            postfix[j] = ch;
            j++;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (top != -1 && peek() != '(')
            {
                postfix[j] = pop();
                j++;
            }
            if (top != -1 && peek() == '(')
            {
                pop();
            }
        }
        else if (isOperator(ch))
        {
            while (top != -1 &&
                   peek() != '(' &&
                   precedence(peek()) >= precedence(ch))
            {
                postfix[j] = pop();
                j++;
            }
            push(ch);
        }
    }
    while (top != -1)
    {
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';
}
int main()
{
    char infix[MAX];
    char postfix[MAX];
    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}