//write a c program , creat a node structure and implement a linked list with basic operations like display &use malloc.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    // Allocate memory for nodes in the linked list
    head = createNode(1);
    second = createNode(2);
    third = createNode(3);

    // Linking the nodes
    head->next = second;
    second->next = third;
    third->next = NULL;

    // Displaying the linked list
    printf("Linked List: ");
    displayList(head);

    return 0;
}