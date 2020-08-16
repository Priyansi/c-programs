#include <stdio.h>
#include <stdlib.h>

int main() {
    int*** arr = (int***)calloc(2, sizeof(int**));
    for (int i = 0; i < 2; ++i) {
        arr[i] = (int**)calloc(2, sizeof(int*));
        for (int j = 0; j < 3; ++j) {
            arr[i][j] = (int*)calloc(3, sizeof(int));
        }
    }
    printf("%d", *(*(*(arr + 0) + 1) + 2));
    return 0;
}