#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int partition(int* arr, int lower_ind, int upper_ind) {
    int i = lower_ind;
    int j = upper_ind;
    int pivot = arr[lower_ind];
    int temp;
    while (1) {
        while (arr[lower_ind] < pivot && i < upper_ind) {
            ++i;
        }
        while (arr[j] > pivot) {
            --j;
        }
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        if (i >= j) {
            return j;
        }
    }
}

void quick_sort(int* arr, int lower_ind, int upper_ind) {
    if (lower_ind < upper_ind) {
        int pivot_ind = partition(arr, lower_ind, upper_ind);
        quick_sort(arr, lower_ind, pivot_ind - 1);
        quick_sort(arr, pivot_ind + 1, upper_ind);
    }
}

int main(int argc, char* argv[]) {
    int arr[] = {3, 2, 1, 5, 4};
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    quick_sort(arr, 0, (sizeof(arr) / sizeof(arr[0])) - 1);
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}