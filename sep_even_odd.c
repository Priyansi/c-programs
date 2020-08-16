// Program to to shift all even elements to one end and all odd ones to another in a randomly generated array given the size
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int arr_len = atoi(argv[1]);
    int pos;
    int arr[arr_len];

    for (pos = 0; pos < arr_len; ++pos) {
        arr[pos] = random() % 50;
    }
    for (pos = 0; pos < arr_len; ++pos) {
        printf("%d ", arr[pos]);
    }
    printf("\n");
    int odd_pos = -1;
    int temp;
    for (pos = 0; pos < arr_len; ++pos) {
        // if odd then swap, quick sort method
        if (arr[pos] & 1) {
            ++odd_pos;
            temp = arr[pos];
            arr[pos] = arr[odd_pos];
            arr[odd_pos] = temp;
        }
    }
    for (pos = 0; pos < arr_len; ++pos) {
        printf("%d ", arr[pos]);
    }

    return 0;
}