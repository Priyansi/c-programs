#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int* arr, int lower_ind, int mid_ind, int upper_ind) {
    int i = lower_ind, j = mid_ind + 1, k = 0;
    int* temp = (int*)malloc((upper_ind - lower_ind + 1) * sizeof(int));
    while (i <= mid_ind && j <= upper_ind) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i];
            ++i;
        } else {
            temp[k++] = arr[j];
            ++j;
        }
    }
    while (i <= mid_ind) {
        temp[k++] = arr[i];
        ++i;
    }
    while (j <= upper_ind) {
        temp[k++] = arr[j];
        ++j;
    }
    for (int i = 0; i < (upper_ind - lower_ind + 1); ++i) {
        arr[lower_ind + i] = temp[i];
    }
}

void merge_sort(int* arr, int lower_ind, int upper_ind) {
    int mid_ind = (lower_ind + upper_ind) / 2;
    if (lower_ind < upper_ind) {
        merge_sort(arr, lower_ind, mid_ind);
        merge_sort(arr, mid_ind + 1, upper_ind);
        merge(arr, lower_ind, mid_ind, upper_ind);
    }
}

int main(int argc, char* argv[]) {
    int arr[] = {3, 5, 8, 9, 4};
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    merge_sort(arr, 0, (sizeof(arr) / sizeof(arr[0])) - 1);
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        printf("%d ", arr[i]);
    }
    return 0;
}