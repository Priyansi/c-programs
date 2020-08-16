// In a one dimensional array find out all the elements and their position, which is the
// summation of its immediate previous contiguous elements.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int arr_len = atoi(argv[1]);
    int pos, temp;
    int* arr = (int*)malloc(arr_len * sizeof(int));

    for (pos = 0; pos < arr_len; ++pos) {
        scanf("%d", &arr[pos]);
    }
    int curr_sum, curr_pos;
    for (pos = arr_len - 1; pos > 0; --pos) {
        curr_sum = 0;
        curr_pos = pos - 1;
        while (curr_sum < arr[pos] && curr_pos >= 0) {
            curr_sum += arr[curr_pos];
            --curr_pos;
        }
        if (curr_sum == arr[pos]) {
            printf("%d %d\n", arr[pos], pos);
        }
    }
    printf("\n");
    return 0;
}