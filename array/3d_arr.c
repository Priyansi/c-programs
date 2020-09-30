#include <stdio.h>
#include <stdlib.h>

int main() {
    int h, r, c, cnt = 1, i, j, k;
    scanf("%d %d %d", &h, &r, &c);
    int*** arr = (int***)malloc(h * sizeof(int**));
    for (i = 0; i < h; ++i) {
        *(arr + i) = (int**)malloc(r * sizeof(int*));
        for (j = 0; j < r; ++j) {
            *(*(arr + i) + j) = (int*)malloc(c * sizeof(int));
            for (k = 0; k < c; ++k) {
                *(*(*(arr + i) + j) + k) = cnt++;
            }
        }
    }

    for (i = 0; i < h; ++i) {
        for (j = 0; j < r; ++j) {
            for (k = 0; k < c; ++k) {
                printf("%d ", *(*(*(arr + i) + j) + k));
            }
            printf("\n");
        }
        printf("\n");
    }
}