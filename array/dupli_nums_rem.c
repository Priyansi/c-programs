#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int num = atoi(argv[1]);
    int i, j;
    int* arr = (int*)calloc(num, sizeof(int*));
    for (i = 0; i < num; ++i) {
        *(arr + i) = random() % 3;
    }
    for (i = 0; i < num; ++i) {
        printf("%d", *(arr + i));
    }
    printf("\n");
    int sum, diff;
    for (i = 0; i < num - 2; ++i) {
        if (*(arr + i) + *(arr + i + 1) < *(arr + i + 2)) {
            arr = (int*)realloc(arr, (num + 1) * sizeof(int));
            sum = *(arr + i + 2);
            diff = sum - (*(arr + i) + *(arr + i + 1));
            *(arr + i + 2) = diff;
            for (j = num; j >= i + 3; --j) {
                *(arr + j) = *(arr + j - 1);
            }
            *(arr + i + 2) = sum;
        }
    }
    for (i = 0; i < num; ++i) {
        printf("%d", *(arr + i));
    }
    printf("\n");
    return 0;
}