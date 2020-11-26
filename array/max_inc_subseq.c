// Program find the maximum number of consecutive elements present in ascending
// order in a randomly generated array

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int arr_len = atoi(argv[1]);
    int pos;
    int* arr = (int*)malloc(arr_len * sizeof(int));

    for (pos = 0; pos < arr_len; ++pos) {
        arr[pos] = random() % 10;
    }
    for (pos = 0; pos < arr_len; ++pos) {
        printf("%d ", arr[pos]);
    }
    printf("\n");
    int max_count, curr_count;
    max_count = curr_count = 1;
    for (pos = 1; pos < arr_len - 1; ++pos) {
        if (arr[pos] > arr[pos - 1]) {
            ++curr_count;
        } else {
            max_count = (curr_count > max_count) ? curr_count : max_count;
            curr_count = 0;
        }
    }

    printf("%d\n", max_count);
    return 0;
}