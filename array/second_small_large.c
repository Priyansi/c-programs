// Program to print largest, second largest, smallest, second smallest in a randomly generated array given the size
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int arr_len = atoi(argv[1]);
    int pos;
    int arr[arr_len];

    for (pos = 0; pos < arr_len; ++pos) {
        arr[pos] = random();
    }
    for (pos = 0; pos < arr_len; ++pos) {
        printf("%d ", arr[pos]);
    }

    int largest, sec_largest, smallest, sec_smallest;
    largest = sec_largest = INT_MIN;
    smallest = sec_smallest = INT_MAX;

    for (pos = 0; pos < arr_len; ++pos) {
        if (arr[pos] > largest) {
            sec_largest = largest;
            largest = arr[pos];
        } else if (arr[pos] > sec_largest) {
            sec_largest = arr[pos];
        }

        if (arr[pos] < smallest) {
            sec_smallest = smallest;
            smallest = arr[pos];
        } else if (arr[pos] < sec_smallest) {
            sec_smallest = arr[pos];
        }
    }

    printf("\nSmallest = %d, Second Smallest = %d, Largest = %d, Second Largest = %d", smallest, sec_smallest, largest, sec_largest);

    return 0;
}