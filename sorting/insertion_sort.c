<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int* arr, int length) {
    int i, j, temp;
    for (i = 1; i < length; ++i) {
        temp = arr[i];
        for (j = i - 1; j >= 0; --j) {
            if (temp >= arr[j]) {
                break;
            }
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
    }
}

int main(int argc, char* argv[]) {
    int arr[] = {3, 5, 8, 9, 4};
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    insertion_sort(arr, sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        printf("%d ", arr[i]);
    }
    return 0;
=======
#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int* arr, int length) {
    int i, j, temp;
    for (i = 1; i < length; ++i) {
        temp = arr[i];
        for (j = i - 1; j >= 0; --j) {
            if (temp >= arr[j]) {
                break;
            }
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
    }
}

int main(int argc, char* argv[]) {
    int arr[] = {3, 2, 1, 5, 4};
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    insertion_sort(arr, sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
>>>>>>> 49abc9210cc5483522466f747b3e9fb753c03de6
}