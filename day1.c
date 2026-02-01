#include <stdio.h>

int main() {
    int a[20];
    int size = 5;
    int index, val;

    for (int i = 0; i < size; i++) {
        a[i] = i + 1; 
    }

    printf("Current array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("Enter index where you want to insert (0 to %d): ", size);
    scanf("%d", &index);

    if (index < 0 || index > size || size >= 20) {
        printf("Invalid index or array full.\n");
        return 1;
    }

    printf("Enter value you want to insert: ");
    scanf("%d", &val);

    for (int i = size; i > index; i--) {
        a[i] = a[i - 1];
        for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    }

    a[index] = val;
    size++;

    printf("Array after insertion:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
