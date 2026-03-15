#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int data;
  struct Node* left;
  struct Node* right;
} node;

node* newnode(int val){
  node* temp = (node*)malloc(sizeof(node));
  temp->data = val;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

struct Queue{
  node** arr;
  int front, rear, size;
};

struct Queue* createQueue(int size){
  struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
  q->arr = (node**)malloc(size * sizeof(node*)); // ✅ FIXED
  q->front = 0;
  q->rear = -1;
  q->size = size;
  return q;
}

int isEmpty(struct Queue* q){
  return q->front > q->rear;
}

void enqueue(struct Queue* q, node* n){
  q->arr[++q->rear] = n;
}

node* dequeue(struct Queue* q){
  return q->arr[q->front++];
}

node* buildTree(int arr[], int n){
  if (n == 0 || arr[0] == -1) return NULL;

  node* root = newnode(arr[0]);
  struct Queue* q = createQueue(n);

  enqueue(q, root);

  int i = 1;

  while (!isEmpty(q) && i < n){
    node* curr = dequeue(q);

    // ✅ LEFT child
    if (i < n && arr[i] != -1){
      curr->left = newnode(arr[i]);
      enqueue(q, curr->left);
    }
    i++;

    // ✅ RIGHT child
    if (i < n && arr[i] != -1){
      curr->right = newnode(arr[i]);
      enqueue(q, curr->right);
    }
    i++;
  }
  return root;
}

void inorder(node* root){
  if (root == NULL) return;

  inorder(root->left);
  printf("%d ", root->data);
  inorder(root->right);
}

int main(){
  int n;
  scanf("%d", &n);

  int* arr = (int*)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }

  node* root = buildTree(arr, n);

  inorder(root);

  return 0;
}
