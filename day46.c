#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node* left;
  struct Node* right;
};

struct Node* createNode(int val){
  struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
  newnode->data=val;
  newnode->left = newnode ->right = NULL;
  return newnode;
}

struct Node* queue[100];
int front = -1, rear = -1;

void enqueue(struct Node* node){
  if(rear == 99)return;
  if(front ==-1) front = 0;
  queue[++rear]=node;
}

struct Node* dequeue(){
  if (front == -1 || front > rear) return NULL;
  return queue[front++];
}

int isEmpty(){
  return (front ==-1 || front > rear);
}

void levelOrder(struct Node* root, int result[], int* size){
  if (root == NULL) return;

  enqueue(root);

  while(!isEmpty()){
    struct Node* curr = dequeue();
    result[(*size)++] = curr -> data;
    if(curr->left !=NULL)enqueue(curr->left);
    if(curr->right != NULL)enqueue(curr->right);
  }
}

int main(){
  struct Node* root = createNode(1);
  root->left = createNode(2);
  root->right = createNode(3);
  root->left->left = createNode(4);
  root->left->right = createNode(5);
  root->right->right = createNode(6);

  int result[100], size=0;
  levelOrder(root, result, &size);

  printf("Level Order Traversal : ");
  for (int i = 0; i<size; i++){
    printf("%d", result[i]);
  }
  return 0;
}

