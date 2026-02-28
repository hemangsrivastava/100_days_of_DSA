
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int value;
  struct node* next;
}node;

node* createnode(int value){
  node* newnode = (node*)malloc(sizeof(node));
  if(!newnode){
    printf("memory allocation failed\n");
    exit(1);
  }
  newnode->value = value;
  newnode->next= newnode;
  return newnode;
}

void insert(node **head, int value){
  node* newnode = createnode(value);
  if (*head == NULL){
    *head = newnode;
  }else{
    node* temp = *head;

    while (temp->next != *head)temp=temp->next;

    newnode->next = *head;
    temp->next = newnode;
    *head = newnode;
  }
printf("%d inserted at beginning.\n",value);
}

void printList(node* head){
  if (head == NULL){
    printf("List is empty\n");
    return;
  }
  node* temp = head;
  printf("circular list: ");

  do{
    printf("%d ->",temp->value);
    temp = temp->next;
  }while(temp!=head);
  printf("head");
  
}

int main(){
    node* head = NULL;

    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);

    printList(head);

    return 0;
}
