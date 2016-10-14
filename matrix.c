#include <stdio.h>
#include <malloc.h>

int main() {
    int **matrix;
    int i, j, m, n;
    scanf ("%d %d", &n, &m);
    matrix = calloc(n, sizeof(int));
    for(i = 0; i < n; i++) {
	    matrix[i] = calloc(m, sizeof(int));
    }
    printf("\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++){
            scanf ("%d", &matrix[i][j]);
        }
    }
    printf ("\n");
    for (j = 0; j < m; j++) {
        for (i = 0; i < n; i++){
            printf ("%d ", matrix[i][j]);
        }
        printf ("\n");
    }
    return 0;
}
