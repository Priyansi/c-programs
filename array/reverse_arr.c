// Program to reverse a randomly generated array given the size
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int arr_len = atoi(argv[1]);
    int pos, temp;
    int arr[arr_len];

    for (pos = 0; pos < arr_len; ++pos) {
        arr[pos] = random();
    }
    for (pos = 0; pos < arr_len; ++pos) {
        printf("%d ", arr[pos]);
    }
    printf("\n");
    for (pos = 0; pos < arr_len / 2; ++pos) {
        temp = arr[pos];
        arr[pos] = arr[arr_len - pos - 1];
        arr[arr_len - pos - 1] = temp;
    }
    for (pos = 0; pos < arr_len; ++pos) {
        printf("%d ", arr[pos]);
    }

    return 0;
}