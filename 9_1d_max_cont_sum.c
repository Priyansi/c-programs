// Copyright 2020 Snehasish [1905356]. All Rights Reserved.

// Q9. In a one dimensional array find out all the elements and their position,
// which is the summation of its immediate previous contiguous elements.
// Ex: Given array: 2,9,6,3,9,8,17,3,6,4,13,5
// Output: output is 9, which is a summation of it’s previous elements 3 and 6
// output is 13, which is a summation of it’s previous elements 4,6 and 3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOWER_LIMIT 0
#define UPPER_LIMIT 50
#define ARR_SIZE 10

int main(int argc, char * argv[]) {
    int size;
    if (argc == 2)
        size = atoi(argv[2]);
    else
        size = ARR_SIZE;

    // // Creating a dynamic array
    // int *a = (int *)malloc(size*sizeof(int));

    // // Filling the array with random numbers
    // int lower = LOWER_LIMIT;
    // int upper = UPPER_LIMIT;
    // srand(time(NULL));
    // for (int i = 0; i < size; i++) {
    //     a[i] = rand()%(upper - lower) + lower;
    // }

    // To test with hardcoded values
    int a[12] = {2, 9, 6, 3, 9, 8, 17, 3, 6, 4, 13, 5};
    size = 12;

    printf("Generated Array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n\n");

    // -------------------------------MAIN LOGIC-------------------------------

    // Flag to check if the code is running with reversed array
    int r2l_check = 0;
    // j_old saves the starting j's value. If we don't find (sum == element)
    // then we will run the loop again with j+=1
    int sum = 0, j, j_old = 0;
    // Checkpoint for reverse array processing
    right_to_left:
    // To store the sum of all the elements before the current element
    sum = 0;
    j_old = 0;

    for (int i = 0; i < size; i++) {
        // Checkpoint to restart J loop with j+=1
        check:
        for (j = j_old; j < i; j++) {
            sum += a[j];
        }
        if (sum == a[i]) {
            if (r2l_check == 0)
                printf("Pos [%d]: %d is sum of ", i+1, a[i]);
            else
                printf("Pos [%d]: %d is sum of ", size-(i+1), a[i]);

            // K loop to print all the elements we added
            for (int k = j_old; k < i; k++)
                printf("%d ", a[k]);
            printf("\n");
            sum = 0;
        } else {
            sum = 0;
            j = ++j_old;

            if (j_old < i)
                // Restart loop with J+=1
                goto check;
        }
        // Resetting j_old value for new array element
        j_old = 0;
    }
    // After we are done with left to right processing, we will reverse the
    // array and process for elements, which is basicallly right to left on
    // a normal array
    if (r2l_check == 0) {
        r2l_check = 1;
        // Right to left
        printf("\n\nFrom right to left:\n");
        // Reverse
        int temp;
        for (int i = 0; i < size/2; i++) {
            temp = a[i];
            a[i] = a[size-1 - i];
            a[size-1 - i] = temp;
        }
        goto right_to_left;
    }
    return 0;
}
