// Program to search a randomly generated array given the size and element to be searched
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int arr_len = atoi(argv[1]);
    int element = atoi(argv[2]);
    int pos;
    int is_found = 0;
    int arr[arr_len];

    for (pos = 0; pos < arr_len; ++pos) {
        arr[pos] = random() % 100;
    }
    for (pos = 0; pos < arr_len; ++pos) {
        printf("%d ", arr[pos]);
    }
    printf("\n");
    for (pos = 0; pos < arr_len; ++pos) {
        if (arr[pos] == element) {
            is_found = 1;
            break;
        }
    }
    printf("%d", (is_found) ? 1 : 0);

    return 0;
}