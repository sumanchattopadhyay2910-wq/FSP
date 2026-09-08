#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

int created() {
    int choice = 1;
    int count = 0;
    struct node *temp = NULL;
    
    while(choice == 1) {
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        if(newnode == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }
        printf("Enter the data for the linked list: ");
        scanf("%d", &newnode->data);
        newnode->prev = NULL;
        newnode->next = NULL;
        
        if(head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
        count++;
        printf("Do you want to add another node (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
    }
    printf("\nDoubly linked list elements (%d total) created.\n", count);
    return 0;
}

int insert_at_beg() {
    int choice = 1;
    while(choice == 1) {
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        if(newnode == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }
        printf("Enter the data for the linked list: ");
        scanf("%d", &newnode->data);
        
        newnode->prev = NULL;
        newnode->next = head;
        
        if(head != NULL) {
            head->prev = newnode;
        }
        head = newnode;
        
        printf("Do you want to enter again? (0 for no / 1 for yes): ");
        scanf("%d", &choice);
    }
    return 0;
}

int insert_at_end() {
    int choice = 1;
    while(choice == 1) {
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        if(newnode == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }
        printf("Enter the data for the linked list: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;
        
        if (head == NULL) {
            head = newnode;
        } else {
            struct node *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->prev = temp;
        }
        
        printf("Do you want to enter again? (0 for no / 1 for yes): ");
        scanf("%d", &choice);
    }
    return 0; 
}

void reverse() {
    struct node *temp = NULL;
    struct node *current = head;

    if (head == NULL) {
        printf("The list is empty. Nothing to reverse.\n");
        return;
    }

    // Har node ke next aur prev pointers ko swap karna
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; // Swap hone ke baad prev hi aage ka pointer ban jata hai
    }

    if (temp != NULL) {
        head = temp->prev;
    }
    printf("Doubly linked list reversed successfully!\n");
}

void print() {
    struct node *temp = head;
    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("NULL <- ");
    while(temp != NULL) {
        if(temp->next != NULL)
            printf("%d <=> ", temp->data);
        else
            printf("%d", temp->data);
        temp = temp->next;
    }
    printf(" -> NULL\n");
}

int main() {
    int choice;
    while(1) {
        printf("\n------menu-------\n");
        printf("Press 1 for create\n");
        printf("Press 2 for enter at the beginning\n");
        printf("Press 3 for enter at the end\n"); 
        printf("Press 4 for print\n");
        printf("Press 5 to exit\n");
        printf("Press 6 for reverse\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: created(); break;
            case 2: insert_at_beg(); break;
            case 3: insert_at_end(); break;
            case 4: print(); break;
            case 5: printf("Exiting program\n"); exit(0);
            case 6: reverse(); break;
            default: printf("Invalid choice, Please try again.\n");
        }
    }
    return 0;
}