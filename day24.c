#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} node;

node* createnode(int value) {
    node* newnode = (node*)malloc(sizeof(node));
    if (!newnode) {
        exit(1);
    }
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

void insertAtEnd(node** head, int value) {
    node* newnode = createnode(value);
    if (*head == NULL) {
        *head = newnode;
        return;
    }
    node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}



void deleteFirstOccurrence(node** head, int key) {
    node *temp = *head, *prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

void printList(node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) printf(" ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    node* head = NULL;
    int n, value, key;

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &value) == 1) {
            insertAtEnd(&head, value);
        }
    }

    if (scanf("%d", &key) != 1) return 0;

    deleteFirstOccurrence(&head, key);
    printList(head);

    return 0;
}
