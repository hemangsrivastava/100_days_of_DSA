#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, columns;

    scanf("%d %d", &rows, &columns);

    if (rows != columns) {
        printf("Not a Symmetric Matrix");
        return 0;
    }

    int **matrix = malloc(rows * sizeof(int*));
    for (int r = 0; r < rows; r++) {
        matrix[r] = malloc(columns * sizeof(int));
    }

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++) {
            scanf("%d", &matrix[r][c]);
        }
    }

    int isSymmetric = 1;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++) {
            if (matrix[r][c] != matrix[c][r]) {
                isSymmetric = 0;
                break;
            }
        }
        if (!isSymmetric)
            break;
    }

    if (isSymmetric)
        printf("Symmetric Matrix");
    else
        printf("Not a Symmetric Matrix");

    for (int r = 0; r < rows; r++) {
        free(matrix[r]);
    }
    free(matrix);

    return 0;
}
