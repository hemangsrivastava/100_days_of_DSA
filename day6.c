#include <stdio.h>
#include <stdlib.h>
int main(){
  int p;

  scanf("%d", &p);
  int *arr = malloc(p * sizeof(int));
    for (int i = 0; i < p; i++) {
        scanf("%d", &arr[i]);
    }

  printf("%d",arr[0]);
  for (int i=1; i<p; i++){
    if (arr[i]!=arr[i-1]){
      printf("%d",arr[i]);
    };
  }
  free(arr);
  return 0;
}
