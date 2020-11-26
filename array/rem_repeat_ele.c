#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int arr_len = atoi(argv[1]);
    int i, j, temp_len = 0, is_repeated;
    int* arr = (int*)malloc(arr_len * sizeof(int));
    int* temp = (int*)malloc(arr_len * sizeof(int));

    for (i = 0; i < arr_len; ++i) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < arr_len; ++i) {
        is_repeated = 0;
        for (j = 0; j < temp_len; ++j) {
            if (arr[i] == arr[j]) {
                is_repeated = 1;
                break;
            }
        }
        if (!is_repeated) {
            temp[temp_len++] = arr[i];
        }
    }
    arr_len = temp_len;
    arr = (int*)realloc(arr, arr_len * sizeof(int));
    for (i = 0; i < arr_len; ++i) {
        arr[i] = temp[i];
    }

    for (i = 0; i < arr_len; ++i) {
        printf("%d ", temp[i]);
    }
    printf("\n");

    return 0;
}