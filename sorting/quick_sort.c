#include <stdio.h>
#include <stdlib.h>

int partition(int* arr, int lower_ind, int upper_ind) {
    int l = lower_ind;
    int u = upper_ind;
    int pivot = arr[lower_ind];
    int temp;
    while (1) {
        while (l <= upper_ind && arr[l] <= pivot) {
            ++l;
        }
        while (u >= lower_ind && arr[u] > pivot) {
            --u;
        }
        if (l >= u) {
            break;
        }
        temp = arr[l];
        arr[l] = arr[u];
        arr[u] = temp;
    }
    temp = arr[lower_ind];
    arr[lower_ind] = arr[u];
    arr[u] = temp;
    return u;
}

void quick_sort(int* arr, int lower_ind, int upper_ind) {
    if (lower_ind < upper_ind) {
        int pivot_ind = partition(arr, lower_ind, upper_ind);
        quick_sort(arr, lower_ind, pivot_ind - 1);
        quick_sort(arr, pivot_ind + 1, upper_ind);
    }
}

int main() {
    int arr[] = {3, 5, 8, 9, 4};

    printf("Unsorted array :\n");
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Sorted array :\n");
    quick_sort(arr, 0, (sizeof(arr) / sizeof(arr[0])) - 1);
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}