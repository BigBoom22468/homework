#include <stdio.h>

int main() {
    int matrix[20][20], i, j, m, n;
    scanf ("%d %d", &n, &m);
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
