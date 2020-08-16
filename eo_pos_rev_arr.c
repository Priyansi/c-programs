// Program to reverse even and odd positions of a randomly generated array given the size

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
    int even_last_pos, odd_last_pos;
    if (arr_len & 1) {
        even_last_pos = arr_len - 1;
        odd_last_pos = arr_len - 2;
    }
    for (pos = 0; pos < arr_len; pos += 2) {
        temp = arr[pos];
        arr[pos] = arr[arr_len - pos - 1];
        arr[arr_len - pos - 1] = temp;
    }
    for (pos = 0; pos < arr_len; ++pos) {
        printf("%d ", arr[pos]);
    }

    return 0;
}