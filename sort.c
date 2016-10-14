#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <malloc.h>

void swap(int32_t* str, int32_t lhs, int32_t rhs) {
    int32_t tmp = str[lhs];
    str[lhs] = str[rhs];
    str[rhs] = tmp;
}

void insertion_sort(int32_t* str, int32_t lenght) {
    int32_t i;
    for (i = 1; i < lenght; ++i) {
        int32_t j = i;
        while (j > 0 && str[j - 1] > str[j]) { // push current to the left
            swap(str, j - 1, j);
            j--;
        }
    }
}
int main() {
    int *str, i, lenght;
    scanf ("%d\n", &lenght);
    str = calloc(lenght, sizeof(int));
    for (i = 0; i < lenght; i++) {
        scanf("%d,", &str[i]);
    }
     insertion_sort(str, lenght);
    for (i = 0; i < lenght; i++) {
        printf("%d ", str[i]);
    }
}
