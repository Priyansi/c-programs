// Program to remove repeated elements in a randomly generated array

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int arr_len = atoi(argv[1]);
    int pos;
    int* arr = (int*)malloc(arr_len * sizeof(int));

    for (pos = 0; pos < arr_len; ++pos) {
        arr[pos] = random() % 10;
    }
    for (pos = 0; pos < arr_len; ++pos) {
        printf("%d ", arr[pos]);
    }
    printf("\n");

    for (pos = 0; pos < arr_len; ++pos) {
        printf("%d ", arr[pos]);
    }

    for (pos = 0; pos < arr_len; ++pos) {
        printf("%d ", arr[pos]);
    }
    printf("\n");
    return 0;
}