#include <stdio.h>
#include <stdlib.h>

int main(){
    int p, q;

    scanf("%d", &p);
    int *log1 = (int *)malloc(p * sizeof(int));
    for (int i = 0; i < p; i++) {
        scanf("%d", &log1[i]);
    }

    scanf("%d", &q);
    int *log2 = (int *)malloc(q * sizeof(int));
    for (int i = 0; i < q; i++) {
        scanf("%d", &log2[i]);
    }

    int *result = (int *)malloc((p + q) * sizeof(int));

    int i,j,k;
    while (i < p && j < q) {
        if (log1[i] <= log2[j]) {
            result[k++] = log1[i++];
        } else {
            result[k++] = log2[j++];
        }
    }

    while (i < p) {
        result[k++] = log1[i++];
    }

    while (j < q) {
        result[k++] = log2[j++];
    }

    for (int x = 0; x < p + q; x++) {
        printf("%d ", result[x]);
    }

    printf("\n");

    free(log1);
    free(log2);
    free(result);

    return 0;
}
