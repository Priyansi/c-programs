// Program to to shift all even elements to one end and all odd ones to another in a randomly generated array given the size
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int arr_len = atoi(argv[1]);
    int pos;
    int* arr = (int*)malloc(arr_len * sizeof(int));

    for (pos = 0; pos < arr_len; ++pos) {
        arr[pos] = random() % 50;
    }
    for (pos = 0; pos < arr_len; ++pos) {
        printf("%d ", arr[pos]);
    }
    printf("\n");
    int i, num, pos_insert;
    scanf("%d", &num);         // number of elements to insert
    scanf("%d", &pos_insert);  // position to insert, not index, index = pos-1
    arr_len += num;
    arr = (int*)realloc(arr, arr_len * sizeof(int));
    // shifting elements back
    for (pos = pos_insert - 1; pos < arr_len; ++pos) {
        arr[pos + num] = arr[pos];
    }
    // insertu=ing new elements
    for (pos = pos_insert - 1; pos < pos_insert + num - 1; ++pos) {
        scanf("%d", &arr[pos]);
    }
    for (pos = 0; pos < arr_len; ++pos) {
        printf("%d ", arr[pos]);
    }

    return 0;
}