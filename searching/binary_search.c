#include <stdio.h>
#include <stdlib.h>

int binary_search_iter(int* arr, int lower_ind, int upper_ind, int val) {
    int mid_ind;
    while (lower_ind <= upper_ind) {
        mid_ind = (lower_ind + upper_ind) / 2;
        if (arr[mid_ind] == val) {
            return 1;
        } else if (arr[mid_ind] > val) {
            upper_ind = mid_ind - 1;
        } else {
            lower_ind = mid_ind + 1;
        }
    }
    return 0;
}

int binary_search_recr(int* arr, int lower_ind, int upper_ind, int val) {
    if (lower_ind <= upper_ind) {
        int mid_ind = (lower_ind + upper_ind) / 2;
        if (arr[mid_ind] == val) {
            return 1;
        } else if (arr[mid_ind] > val) {
            return binary_search_recr(arr, lower_ind, mid_ind - 1, val);
        } else {
            return binary_search_recr(arr, mid_ind + 1, upper_ind, val);
        }
    }
    return 0;
}

int main(int argc, char* argv[]) {
    int arr[] = {3, 9, 10, 16, 20, 25, 27, 32, 34, 37};
    printf("%d\n", binary_search_recr(arr, 0, (sizeof(arr) / sizeof(arr[0])) - 1, 27));
    printf("%d\n", binary_search_iter(arr, 0, (sizeof(arr) / sizeof(arr[0])) - 1, 33));
    return 0;
}