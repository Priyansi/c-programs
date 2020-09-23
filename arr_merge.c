#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int arr_len1 = atoi(argv[1]);
    int arr_len2 = atoi(argv[2]);
    int pos;
    int* arr1 = (int*)malloc(arr_len1 * sizeof(int));
    int* arr2 = (int*)malloc((arr_len1 + arr_len2) * sizeof(int));

    for (pos = 0; pos < arr_len1; ++pos) {
        scanf("%d", arr1 + pos);
    }
    for (pos = 0; pos < arr_len2; ++pos) {
        scanf("%d", arr2 + pos);
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