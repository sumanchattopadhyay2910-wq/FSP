#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *front = NULL;
struct Node *rear = NULL;
void enqueue()
{
    int value;
    struct Node *newNode;
    printf("Enter value to insert: ");
    scanf("%d", &value);
    newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (front == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {     rear->next = newNode;   rear = newNode;}
    printf("%d inserted successfully.\n", value);
}

void dequeue()
{
    struct Node *temp;
    if (front == NULL)
    {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }
   temp = front;
   printf("%d deleted successfully.\n", front->data);
   front = front->next;
   if (front == NULL)
    {        rear = NULL;    }
    free(temp);
}



void peek()
{
    if (front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Front element = %d\n", front->data);
}
void display()
{
    struct Node *temp;
    if (front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }
    temp = front;
    printf("Queue elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}


/* Function to count nodes */
void count()
{
    struct Node *temp;
    int count = 0;

    temp = front;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    printf("Number of elements = %d\n", count);
}


/* Main function */
int main()
{
    int choice;

    while (1)
    {
        printf("\n============================\n");
        printf("       QUEUE MENU\n");
        printf("============================\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Count\n");
        printf("6. Exit\n");
        printf("============================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                count();
                break;

            case 6:
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}