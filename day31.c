#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top < MAX - 1) {
        stack[++top] = value;
    }
}

void pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
    } else {
        printf("%d\n", stack[top--]);
    }
}

void display() {
    for (int i = top; i >= 0; i--) {
        printf("%d%s", stack[i], (i == 0 ? "" : " "));
    }
    printf("\n");
}

int main() {
    int n, choice, value;

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &choice) != 1) break;
        
        if (choice == 1) {
            scanf("%d", &value);
            push(value);
        } else if (choice == 2) {
            pop();
        } else if (choice == 3) {
            display();
        }
    }

    return 0;
}
