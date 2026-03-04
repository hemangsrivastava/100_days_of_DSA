#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void push(int num, int *stack, int *top) {
    if (*top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    (*top)++;
    stack[*top] = num;
    printf("%d pushed to stack\n", num);
}

int pop(int *stack, int *top) {
    if (*top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    }
    int value = stack[*top];
    (*top)--;
    printf("%d popped from stack\n", value);
    return value;
}

int peek(int *stack, int top) {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top];
}

void display(int *stack, int top) {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements (top to bottom):\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    int stack[MAX];
    int top = -1;
    int choice, value;

    while (1) {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value, stack, &top);
                break;

            case 2:
                pop(stack, &top);
                break;

            case 3:
                value = peek(stack, top);
                if (value != -1)
                    printf("Top element: %d\n", value);
                break;

            case 4:
                display(stack, top);
                break;

            case 5:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
