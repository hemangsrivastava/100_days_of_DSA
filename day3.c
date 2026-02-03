#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    scanf("%d", &size);

    int *arr = malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &arr[i]);
    }

    int val;
    printf("Enter the number you want to search: ");
    scanf("%d", &val);

    int count = 0;
    int found = 0;

    for (int i = 0; i < size; i++) {
        count++;

        if (arr[i] == val) {
            printf("The number %d was found at index %d\n", val, i);
            found = 1;
        }
    }

    if (found == 0) {
        printf("Number not found\n");
    }

    printf("Number of items searched: %d\n", count);

    free(arr);
    return 0;
}
