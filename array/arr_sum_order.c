#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int num = atoi(argv[1]);
    int i, j;
    int* arr = (int*)calloc(num, sizeof(int*));

    for (i = 0; i < num; ++i) {
        *(arr + i) = random() % 10;
    }

    for (i = 0; i < num; ++i) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    int reqd_sum, diff, len_arr = num;
    for (i = 0; i < num - 2; i += 3) {
        if (*(arr + i) + *(arr + i + 1) < *(arr + i + 2)) {
            if (num == len_arr) {
                len_arr = num * 2;
                arr = (int*)realloc(arr, len_arr * sizeof(int));
            }

            reqd_sum = *(arr + i + 2);
            diff = reqd_sum - (*(arr + i) + *(arr + i + 1));
            *(arr + i + 2) = diff;

            for (j = num; j >= i + 3; --j) {
                *(arr + j) = *(arr + j - 1);
            }

            *(arr + i + 3) = reqd_sum;
            ++num;
            ++i;
        }
    }

    for (i = 0; i < num; ++i) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
    return 0;
}