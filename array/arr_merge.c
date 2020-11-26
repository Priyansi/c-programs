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
    for (pos = 0; pos < arr_len1; ++pos) {
        arr2[arr_len2 + pos] = arr1[pos];
    }
    int p1 = 0, p2 = arr_len2, temp;
    while (p1 < arr_len1 + arr_len2) {
        if (arr2[p2] > arr1[p1]) {
            temp = arr2[p2];
            arr2[p2] = arr1[p1];
            arr1[p1] = temp;
        }
        ++p1;
        ++p2;
    }
    for (pos = 0; pos < arr_len1 + arr_len2; ++pos) {
        printf("%d ", arr2[pos]);
    }

    return 0;
}