#include <stdio.h>
#include <stdlib.h>

int sequential_search(int* arr, int length, int val) {
    for (int i = 0; i < length; ++i) {
        if (arr[i] == val) {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char* argv[]) {
    int arr[] = {3, 9, 10, 16, 20, 25, 27, 32, 34, 37};
    printf("%d\n", sequential_search(arr, sizeof(arr) / sizeof(arr[0]), 27));
    return 0;
}