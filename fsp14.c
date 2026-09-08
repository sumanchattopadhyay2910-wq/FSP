#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Forward declaration of deleteNode
void deleteNode(struct Node** head_ref, struct Node* current);

void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    new_node->prev = NULL;

    if (*head_ref != NULL)
        (*head_ref)->prev = new_node;

    *head_ref = new_node;
}

void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    new_node->prev = last;
}

void insertAtPosition(struct Node** head_ref, int new_data, int position) {
    if (position <= 0) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1) {
        insertAtBeginning(head_ref, new_data);
        return;
    }

    struct Node* current = *head_ref;
    for (int i = 1; current != NULL && i < position - 1; i++)
        current = current->next;

    if (current == NULL) {
        printf("Position out of range.\n");
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;

    new_node->next = current->next;
    new_node->prev = current;

    if (current->next != NULL)
        current->next->prev = new_node;

    current->next = new_node;
}

void displayList(struct Node* node) {
    if (node == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* last = NULL;
    printf("Traversal in forward direction:\n");
    while (node != NULL) {
        printf("%d ", node->data);
        last = node;
        node = node->next;
    }

    printf("\nTraversal in reverse direction:\n");
    while (last != NULL) {
        printf("%d ", last->data);
        last = last->prev;
    }
    printf("\n");
}

void deleteNode(struct Node** head_ref, struct Node* current) {
    if (*head_ref == NULL || current == NULL)
        return;

    // If node to be deleted is head node
    if (*head_ref == current)
        *head_ref = current->next;

    // Change next only if node to be deleted is NOT the last node
    if (current->next != NULL)
        current->next->prev = current->prev;

    // Change prev only if node to be deleted is NOT the first node
    if (current->prev != NULL)
        current->prev->next = current->next;

    free(current);
}

void deleteNodeAtBeginning(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is already empty.\n");
        return;
    }
    deleteNode(head_ref, *head_ref);
}

void deleteNodeAtPosition(struct Node** head_ref, int position) {
    if (*head_ref == NULL || position <= 0) {
        printf("Invalid position or empty list.\n");
        return;
    }

    struct Node* current = *head_ref;
    for (int i = 1; current != NULL && i < position; i++)
        current = current->next;

    if (current == NULL) {
        printf("Position out of range.\n");
        return;
    }

    deleteNode(head_ref, current);
}

void reverseList(struct Node** head_ref) {
    if (*head_ref == NULL || (*head_ref)->next == NULL)
        return; // Empty or single element list is already reversed

    struct Node* temp = NULL;
    struct Node* current = *head_ref;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
        *head_ref = temp->prev;
}

int main() {
    int choice, value, position;
    struct Node* head = NULL;
    printf("Doubly Linked List Operations:\n");

    while (1) {
        printf("\n1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at Position\n");
        printf("6. Display List\n");
        printf("7. Reverse List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                insertAtPosition(&head, value, position);
                break;
            case 4:
                deleteNodeAtBeginning(&head);
                break;
            case 5:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteNodeAtPosition(&head, position);
                break;
            case 6:
                displayList(head);
                break;
            case 7:
                reverseList(&head);
                printf("List reversed successfully.\n");
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}