// Program to find maximum consecutive ascending elements a randomly generated array given the size
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int arr_len = atoi(argv[1]);
    int pos, temp;
    int arr[arr_len];

    for (pos = 0; pos < arr_len; ++pos) {
        arr[pos] = random() % 50;
    }
    for (pos = 0; pos < arr_len; ++pos) {
        printf("%d ", arr[pos]);
    }
    printf("\n");
    int max_count, curr_count;
    max_count = curr_count = 1;
    for (pos = 1; pos < arr_len; ++pos) {
        if (arr[pos - 1] < arr[pos]) {
            ++curr_count;
        } else {
            max_count = (curr_count > max_count) ? curr_count : max_count;
            curr_count = 1;
        }
    }
    printf("%d\n", max_count);

    return 0;
}