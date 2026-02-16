#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 1000

typedef struct Node {
    int key;
    int count;
    struct Node* next;
} Node;

Node* table[TABLE_SIZE];

int hash(int key) {
    if (key < 0) key = -key;
    return key % TABLE_SIZE;
}

void insert(int key) {
    int index = hash(key);
    Node* current = table[index];

    while (current != NULL) {
        if (current->key == key) {
            current->count++;
            return;
        }
        current = current->next;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->count = 1;
    newNode->next = table[index];
    table[index] = newNode;
}

void printFrequencies() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = table[i];
        while (current != NULL) {
            printf("%d:%d ", current->key, current->count);
            current = current->next;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int num;

    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        insert(num);
    }

    printFrequencies();

    return 0;
}
