#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int data;
  struct Node *next;
}node;

node* createnode(int value){
  node* newnode = (node*)malloc(sizeof(node));
  if (!newnode){
    printf("Memory allocation failed");
    exit(1);
  }
  newnode->data = value;
  newnode->next = NULL;
  return newnode;
}

void insertAtBeginning(node** head, int value){
  node* newnode = createnode(value);
  newnode -> next = *head;
  *head = newnode;
  printf("inserted node at beginning.\n");
}

void printlist(node * head){
  if (head == NULL){
    printf("the list is empty");
    return;
  }
  node * temp = head;
  printf("Linked List :");
  while (temp!=NULL){
    printf("%d ->", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

void count(node * head){
  int c;
  if (head == NULL){
    printf("0");
    return;
  }
  node * temp = head;
  while (temp!=NULL){
    c = c+1;
    temp = temp->next;
  }
  printf("The number of nodes are %d",c);
}

int main(){
  node* head = NULL;
  insertAtBeginning(&head, 18);
  insertAtBeginning(&head, 3);
  insertAtBeginning(&head, 1);
  printlist(head);
  count(head);
}
