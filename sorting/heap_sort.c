#include <stdio.h>
#include <stdlib.h>

void max_heapify_node(int* arr, int parent_ind, int size) {
    int max = parent_ind, left_child_ind = 2 * parent_ind + 1, right_child_ind = 2 * parent_ind + 2;
    if (left_child_ind < size && arr[left_child_ind] > arr[max]) {
        max = left_child_ind;
    }
    if (right_child_ind < size && arr[right_child_ind] > arr[max]) {
        max = right_child_ind;
    }
    if (max != parent_ind) {
        int temp = arr[parent_ind];
        arr[parent_ind] = arr[max];
        arr[max] = temp;
        max_heapify_node(arr, parent_ind, size);
    }
}

void max_heapify(int* arr, int size) {
    for (int i = size / 2 - 1; i >= 0; --i) {
        max_heapify_node(arr, i, size);
    }
}

void heap_sort(int* arr, int size) {
    int temp;
    // max heapify the entire array first
    max_heapify(arr, size);
    while (size > 0) {
        // swap first and last node
        temp = arr[0];
        arr[0] = arr[size - 1];
        arr[size - 1] = temp;
        // max heapify the first node that has been changed
        max_heapify_node(arr, 0, --size);
    }
}

int main(int argc, char* argv[]) {
    int arr[] = {3, 5, 8, 9, 4};
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    heap_sort(arr, sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        printf("%d ", arr[i]);
    }
    return 0;
}