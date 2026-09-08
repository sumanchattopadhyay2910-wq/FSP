#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node* createNode(int value)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}


void createList(struct Node **head)
{
    int n, i, value;

    struct Node *newNode;
    struct Node *temp;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("Enter data for node %d: ", i);
        scanf("%d", &value);

        newNode = createNode(value);

       
        if (*head == NULL)
        {
            *head = newNode;
            newNode->next = *head;
        }
        else
        {
            temp = *head;

            
            while (temp->next != *head)
            {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->next = *head;
        }
    }
}


void display(struct Node *head)
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    temp = head;

    printf("\nCircular Linked List:\n");

    do
    {
        printf("%d", temp->data);

        temp = temp->next;

        if (temp != head)
        {
            printf(" -> ");
        }

    } while (temp != head);

    printf(" -> HEAD\n");
}


void insertBeginning(struct Node **head, int value)
{
    struct Node *newNode;
    struct Node *temp;
    newNode = createNode(value);
   
    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = *head;
        printf("Node inserted at beginning.\n");
        return;
    } 
    temp = *head;
    while (temp->next != *head)
    {temp = temp->next;    }
     newNode->next = *head;    
    temp->next = newNode;    
    *head = newNode;
    printf("Node inserted at beginning.\n");
}


void insertEnd(struct Node **head, int value)
{
    struct Node *newNode;
    struct Node *temp;
    newNode = createNode(value);
       if (*head == NULL)
    {
        *head = newNode;
        newNode->next = *head;
        printf("Node inserted at end.\n");
        return;
    }
    temp = *head;
    while (temp->next != *head)
    { temp = temp->next;}
   temp->next = newNode; 
    newNode->next = *head;
    printf("Node inserted at end.\n");
}


void insertPosition(struct Node **head, int value, int position)
{
    struct Node *newNode;
    struct Node *temp;
    int i;
   if (position <= 0)
    {
        printf("Invalid position!\n");
        return;
    }
    
    if (position == 1)
    {
        insertBeginning(head, value);
        return;
    }
   if (*head == NULL)
    {
        printf("Invalid position!\n");
        return;
    }
    temp = *head;
    for (i = 1; i < position - 1; i++)
    {   temp = temp->next;
        if (temp == *head)
        {      printf("Invalid position!\n");
            return; }  }
    newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Node inserted at position %d.\n", position);
}


void insertAfterValue(struct Node **head, int value, int afterValue)
{
    struct Node *temp;
    struct Node *newNode;

    if (*head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    temp = *head;

    
    do
    {
        if (temp->data == afterValue)
        {
            newNode = createNode(value);

            newNode->next = temp->next;
            temp->next = newNode;

            printf("%d inserted after %d.\n", value, afterValue);
            return;
        }

        temp = temp->next;

    } while (temp != *head);

    printf("Value %d not found!\n", afterValue);
}


void insertBeforeValue(struct Node **head, int value, int beforeValue)
{
    struct Node *temp;
    struct Node *prev;
    struct Node *newNode;

    if (*head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    
    if ((*head)->data == beforeValue)
    {
        insertBeginning(head, value);
        return;
    }

    prev = *head;
    temp = (*head)->next;

    
    while (temp != *head)
    {
        if (temp->data == beforeValue)
        {
            newNode = createNode(value);

            newNode->next = temp;
            prev->next = newNode;

            printf("%d inserted before %d.\n", value, beforeValue);
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Value %d not found!\n", beforeValue);
}


int main()
{
    struct Node *head = NULL;

    int choice;
    int value;
    int position;
    int referenceValue;

    
    printf("===== CREATE CIRCULAR LINKED LIST =====\n");

    createList(&head);

  
    while (1)
    {
        printf("\n\n===== CIRCULAR LINKED LIST MENU =====\n");

        printf("1. Display\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Specific Position\n");
        printf("5. Insert After a Given Value\n");
        printf("6. Insert Before a Given Value\n");
        printf("7. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:

                display(head);

                break;

            case 2:

                printf("Enter value: ");
                scanf("%d", &value);

                insertBeginning(&head, value);

                break;

            case 3:

                printf("Enter value: ");
                scanf("%d", &value);

                insertEnd(&head, value);

                break;

            case 4:

                printf("Enter value: ");
                scanf("%d", &value);

                printf("Enter position: ");
                scanf("%d", &position);

                insertPosition(&head, value, position);

                break;

            case 5:

                printf("Enter value to insert: ");
                scanf("%d", &value);

                printf("Enter value after which to insert: ");
                scanf("%d", &referenceValue);

                insertAfterValue(&head, value, referenceValue);

                break;

            case 6:

                printf("Enter value to insert: ");
                scanf("%d", &value);

                printf("Enter value before which to insert: ");
                scanf("%d", &referenceValue);

                insertBeforeValue(&head, value, referenceValue);

                break;

            case 7:

                printf("Program terminated.\n");
                exit(0);

            default:

                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}