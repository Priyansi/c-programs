// Program to reverse even and odd positions of a randomly generated array given the size

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
    int pos_del;
    scanf("%d", &pos_del);

    for (pos = pos_del + 1; pos < arr_len; ++pos) {
        arr[pos - 1] = arr[pos];
    }
    arr_len -= 1;
    arr = (int*)realloc(arr, arr_len * sizeof(int));
    for (pos = 0; pos < arr_len; ++pos) {
        printf("%d ", arr[pos]);
    }

    return 0;
}