/*
Write a program to find the intersection of two sets(consider each set is an array)
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int arr_len1 = atoi(argv[1]);
    int arr_len2 = atoi(argv[2]);
    // arr_len1 should always be greater
    if (arr_len1 < arr_len2) {
        arr_len1 = arr_len1 + arr_len2;
        arr_len2 = arr_len1 - arr_len2;
        arr_len1 = arr_len1 - arr_len2;
    }
    int pos;
    int* arr1 = (int*)malloc(arr_len1 * sizeof(int));
    int* arr2 = (int*)malloc(arr_len2 * sizeof(int));

    for (pos = 0; pos < arr_len1; ++pos) {
        arr1[pos] = random() % 10;
    }
    for (pos = 0; pos < arr_len2; ++pos) {
        arr2[pos] = random() % 10;
    }
    for (pos = 0; pos < arr_len1; ++pos) {
        printf("%d ", arr1[pos]);
    }
    printf("\n");
    for (pos = 0; pos < arr_len2; ++pos) {
        printf("%d ", arr2[pos]);
    }
    printf("\n");
    int start_pos = 0, flag;
    while (arr_len2 + start_pos < arr_len1) {
        flag = 1;
        for (pos = 0; pos < arr_len2; ++pos) {
            if (arr2[pos] != arr1[pos + start_pos]) {
                flag = 0;
            }
        }
        if (flag) {
            break;
        }
        ++start_pos;
    }

    printf(flag ? "Yes" : "No");
    return 0;
}