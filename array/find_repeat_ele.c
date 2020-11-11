#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int arr_len = atoi(argv[1]);
    int i, j, k = 0, is_visited;
    int* arr = (int*)malloc(arr_len * sizeof(int));
    int* repeating_elements = (int*)malloc(arr_len * sizeof(int));

    for (i = 0; i < arr_len; ++i) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < arr_len; ++i) {
        for (j = i + 1; j < arr_len; ++j) {
            if (arr[i] == arr[j]) {
                repeating_elements[k++] = arr[i];
            }
        }
    }
    for (i = 0; i < k; ++i) {
        is_visited = 0;
        for (j = 0; j < i; ++j) {
            if (repeating_elements[i] == repeating_elements[j]) {
                is_visited = 1;
                break;
            }
        }
        if (!is_visited) {
            printf("%d ", repeating_elements[i]);
        }
    }
    printf("\n");

    return 0;
}