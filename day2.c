#include <stdio.h>

int main() {
    int a[20];
    int size;
    int pos;

    printf("Enter number of elements: ");
    scanf("%d", &size);

    printf("Enter the elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    int index = pos - 1;

    for (int i = index; i < size - 1; i++) {
        a[i] = a[i + 1];
    }

    size--;  
    printf("Array after deletion:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
