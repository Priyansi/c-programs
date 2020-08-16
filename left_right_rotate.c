// In a one dimensional array, user gives a certain range of index with shifting value. You need
// to right shift and rotate those range of values based on the given shifting value. Do the same
// for left shift

// reversal algo

#include <stdio.h>
#include <stdlib.h>

// reverse array between two indexes, indexes included
void reverse(int*, int, int);

void reverse(int* arr, int ind1, int ind2) {
    int temp, len = ind2 - ind1 + 1;
    for (int cnt = 0; cnt < len / 2; ++cnt) {
        temp = arr[ind1 + cnt];
        arr[ind1 + cnt] = arr[ind2 - cnt];
        arr[ind2 - cnt] = temp;
    }
}

int main(int argc, char* argv[]) {
    int arr_len = atoi(argv[1]);
    char choice = argv[2][0];
    int ind1 = atoi(argv[3]);
    int ind2 = atoi(argv[4]);
    int shift = atoi(argv[5]);
    int pos;
    int* arr = (int*)malloc(arr_len * sizeof(int));

    for (pos = 0; pos < arr_len; ++pos) {
        arr[pos] = random() % 20;
    }
    for (pos = 0; pos < arr_len; ++pos) {
        printf("%d ", arr[pos]);
    }
    printf("\n");

    shift = shift % (ind2 - ind1 + 1);
    int temp, len;

    if (choice == 'l') {
        // between 1 and shift
        reverse(arr, ind1, ind1 + shift - 1);
        // between shift+1 and len
        reverse(arr, ind1 + shift, ind2);
        // entire array
        reverse(arr, ind1, ind2);
    } else if (choice == 'r') {
        // between shift+1 and len
        reverse(arr, ind1 + shift, ind2);
        // between 1 and shift
        reverse(arr, ind1, ind1 + shift - 1);
        // entire array
        reverse(arr, ind1, ind2);
    }

    for (pos = 0; pos < arr_len; ++pos) {
        printf("%d ", arr[pos]);
    }
    printf("\n");
    return 0;
}