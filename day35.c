#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void enque(int num, int *queue, int *rear, int *front){
  if (*rear == MAX-1){
      printf("Queve is full");
      return;
  }
  *rear = *rear +1;
  queue[*rear]=num;
  *front = 0;  

}

void deque(int *queue, int *rear, int *front){
  if(*rear == -1){
    printf("queue is empty");
    return;
  }
  *front = *front + 1;
}

void display(int *queue, int rear, int top) {
    if (rear == -1) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements (top to bottom):\n");
    for (int i = top; i <= rear; i++) {
        printf("%d\n", queue[i]);
    }
}


int main(){
  int rear=-1;
  int top=-1;
  int queue[MAX];
  int choice, value;
  while (1) {
        printf("\n--- QUEUE MENU ---\n");
        printf("1. enque\n");
        printf("2. deque\n");
        printf("3. Display\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                enque(value, queue, &rear, &top);
                break;

            case 2:
                deque(queue, &rear, &top);
                break;

            case 3:
                display(queue, rear, top);
                break;

            case 5:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

}
