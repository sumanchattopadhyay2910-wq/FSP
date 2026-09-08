#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *prev;
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
    newNode->prev = NULL;
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
        {  *head = newNode;   }
        else
        {    temp = *head;
      while (temp->next != NULL)
            {  temp = temp->next;            }

            temp->next = newNode;
            newNode->prev = temp; }}}
void display(struct Node *head)
{    struct Node *temp = head;
    if (head == NULL)
    {    printf("List is empty!\n");
        return;
    }
    printf("\nDoubly Linked List:\n");
    while (temp != NULL)
    {
        printf("%d", temp->data);
        if (temp->next != NULL)
        {            printf(" <-> ");        }
        temp = temp->next;    }
    printf(" -> NULL\n");}

void insertBeginning(struct Node **head, int value)
{
    struct Node *newNode;
    newNode = createNode(value);
    if (*head != NULL)
    {   newNode->next = *head;
        (*head)->prev = newNode;
    }
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
        printf("Node inserted at end.\n");
        return;
    }
    temp = *head;
        while (temp->next != NULL)
    {        temp = temp->next;    }
    temp->next = newNode;
    newNode->prev = temp;
    printf("Node inserted at end.\n");
}
void insertPosition(struct Node **head, int value, int position)
{
    struct Node *newNode;
    struct Node *temp;
    int i;
    
    if (position == 1)
    {
        insertBeginning(head, value);
        return;
    }
    newNode = createNode(value);
    temp = *head;
    for (i = 1; i < position - 1 && temp != NULL; i++)
    {        temp = temp->next;    }    
    if (temp == NULL)
    {
        printf("Invalid position!\n");
        free(newNode);
        return;
    }    
    newNode->next = temp->next;
    newNode->prev = temp;
   if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    printf("Node inserted at position %d.\n", position);
}

void insertAfterValue(struct Node **head, int value, int afterValue)
{
    struct Node *temp;
    struct Node *newNode;

    temp = *head;

   
    while (temp != NULL && temp->data != afterValue)
    {
        temp = temp->next;
    }

   
    if (temp == NULL)
    {
        printf("Value %d not found!\n", afterValue);
        return;
    }

    newNode = createNode(value);

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }

    temp->next = newNode;

    printf("%d inserted after %d.\n", value, afterValue);
}


void insertBeforeValue(struct Node **head, int value, int beforeValue)
{
    struct Node *temp;
    struct Node *newNode;

    temp = *head;

   
    while (temp != NULL && temp->data != beforeValue)
    {
        temp = temp->next;
    }

    
    if (temp == NULL)
    {
        printf("Value %d not found!\n", beforeValue);
        return;
    }

    
    if (temp == *head)
    {
        insertBeginning(head, value);
        return;
    }
    newNode = createNode(value);
    newNode->next = temp;
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    temp->prev = newNode;
    printf("%d inserted before %d.\n", value, beforeValue);
}


int main()
{
    struct Node *head = NULL;

    int choice;
    int value;
    int position;
    int referenceValue;

    
    printf("===== CREATE DOUBLY LINKED LIST =====\n");

    createList(&head);

    while (1)
    {
        printf("\n\n===== DOUBLY LINKED LIST MENU =====\n");
        printf("1. Display\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Specific Position\n");
        printf("5. Insert After a Given Value\n");
        printf("6. Insert Before a Given Value\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
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
                printf("Invalid choice!\n");
        }
    }

    return 0;
}