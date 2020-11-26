// Program to delete all even elements of a randomly generated array given the size

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int arr_len = atoi(argv[1]);
    int pos, temp;
    int* arr = (int*)malloc(arr_len * sizeof(int));

    for (pos = 0; pos < arr_len; ++pos) {
        scanf("%d", &arr[pos]);
    }
    int curr_sum, curr_pos, is_asc, is_desc;
    for (pos = arr_len - 1; pos > 0; --pos) {
        curr_pos = pos - 1;
        curr_sum = arr[curr_pos--];
        is_asc = is_desc = 1;
        while (curr_sum < arr[pos] && curr_pos > 1 && (is_asc == 1 || is_desc == 1)) {
            curr_sum += arr[curr_pos];
            if (arr[curr_pos] > arr[curr_pos - 1]) {
                is_desc = 0;
            } else if (arr[curr_pos] < arr[curr_pos - 1]) {
                is_asc = 0;
            }
            --curr_pos;
        }
        if (curr_sum == arr[pos] && (is_asc == 1 || is_desc == 1)) {
            printf("%d %d", arr[pos], pos);
        }
    }
    printf("\n");
    return 0;
}