#include <stdio.h>
#include <stdlib.h>

int main(){
  int rows, cols;
  int sum;
  printf("Enter rows and columns\n");
  scanf("%d %d", &rows, &cols);

  int **matrix = malloc(rows * sizeof(int *));
  for (int i=0; i<rows; i++){
    matrix[i] = malloc(cols * sizeof(int));
  }

  printf("Enter matrix elements\n");
  for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

  int min = rows < cols ? rows : cols;

  printf("Main Diagonal : ");
  for (int i=0; i<min; i++){
    printf("%d ", matrix[i][i]);
    sum += matrix[i][i];
    
  }
  printf("\nthe sum of the diagnols is: %d",sum);

  for (int i=0; i<rows; i++){
    free(matrix[i]);
  }
  free(matrix);

  return 0;


}
