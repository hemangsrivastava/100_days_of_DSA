#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int value;
  struct node* next;
}node;

node* createnode(int value){
  node* newnode = (node*)malloc(sizeof(node));
  if(!newnode){
    printf("Memory alocation failed\n");
    exit(1);
  }
  newnode->value = value;
  newnode->next = NULL;
  return newnode;
}

void insertAtBeginning(node** head, int value){
 node* newnode = createnode(value);
 newnode -> next = *head;
 *head = newnode;
 printf("inserted node at the beginning.\n, value");
}

void deleteFirstNode(node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    node* temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("First node deleted.\n");
}

	
void printList(node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    node* temp = head;
    printf("Linked list: ");
    while (temp != NULL) {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}

int Count(node* head) {
    int count = 0;
    node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

int main() {
node* head = NULL;
insertAtBeginning(&head, 56);
insertAtBeginning(&head, 6);
insertAtBeginning(&head, 561);
insertAtBeginning(&head, 563);
insertAtBeginning(&head, 564);
printList(head);
int count = Count(head);
printf("The number of nodes are %d",count);
  return 0;

}
