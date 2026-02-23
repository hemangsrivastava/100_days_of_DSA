#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int data;
  struct Node* next;
}node;

node* createNode(int data){
  node* newnode = (node*)malloc(sizeof(node));
  newnode->data=data;
  newnode->next=NULL;
  return newnode;
}

void append(node** head, int data){
  node* newnode = createNode(data);
  if (*head ==NULL){
    *head=newnode;
    return;
  }

  node* temp = *head;
  while (temp->next != NULL){
    temp = temp -> next;
  temp->next = newnode;
  }
}

node *merge(node* l1, node* l2){
  node dummy;
  node* tail = &dummy;
  dummy.next=NULL;

  while (l1 != NULL && l2 != NULL){
    if (l1->data <= l2->data){
      tail -> next = l1;
      l1 = l1->next;
    }else{
      tail->next=l2;
      l2 = l2->next;
    }
    tail = tail->next;
  }
  if (l1 != NULL) tail->next = l1;
  else tail->next=l2;

  return dummy.next;
}

void printList(struct Node* head){
  while (head != NULL){
    printf("%d ",head->data);
    head = head->next;
  }
}


int main() {
    int n, m, value;
    struct Node *list1 = NULL, *list2 = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        append(&list1, value);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        append(&list2, value);
    }

    struct Node* merged = merge(list1, list2);

    printList(merged);

    return 0;
}
