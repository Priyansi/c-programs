// Program to delete all even elements of a randomly generated array given the size

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int arr_len = atoi(argv[1]);
    int pos, temp;
    int* arr = (int*)malloc(arr_len * sizeof(int));

    for (pos = 0; pos < arr_len; ++pos) {
        arr[pos] = random() % 100;
    }
    for (pos = 0; pos < arr_len; ++pos) {
        printf("%d ", arr[pos]);
    }
    printf("\n");
    int last_odd_pos = 0, new_len = arr_len;
    for (pos = 0; pos < arr_len; ++pos) {
        while (arr[pos] % 2 == 0) {
            ++pos;
            --new_len;
        }
        arr[last_odd_pos] = arr[pos];
        ++last_odd_pos;
    }
    arr = (int*)realloc(arr, new_len * sizeof(int));
    for (pos = 0; pos < new_len; ++pos) {
        printf("%d ", arr[pos]);
    }
    printf("\n");
    return 0;
}