#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);
    int row, col;
    int** arr = (int**)calloc(rows, sizeof(int*));
    for (row = 0; row < rows; ++row) {
        arr[row] = (int*)calloc(cols, sizeof(int));
        for (col = 0; col < cols; ++col) {
            *(*(arr + row) + col) = random() % 10;
        }
    }
    //printing original array
    for (row = 0; row < rows; ++row) {
        for (col = 0; col < cols; ++col) {
            printf("%d", *(*(arr + row) + col));
        }
        printf("\n");
    }
    // left aligned triangle
    for (row = 0; row < rows; ++row) {
        for (col = 0; col <= row; ++col) {
            printf("%d", *(*(arr + row) + col));
        }
        printf("\n");
    }
    // right aligned triangle
    printf("\n");
    for (row = 0; row < rows; ++row) {
        if (rows - row - 1) {
            printf("%*c", rows - row - 1, ' ');
        }
        for (col = cols - 1 - row; col < cols; ++col) {
            printf("%d", *(*(arr + row) + col));
        }
        printf("\n");
    }
    // left aligned inverted triangle
    printf("\n");
    for (row = 0; row < rows; ++row) {
        for (col = 0; col < cols - row; ++col) {
            printf("%d", *(*(arr + row) + col));
        }
        printf("\n");
    }
    printf("\n");
    // right aligned inverted triangle
    for (row = 0; row < rows; ++row) {
        if (row) {
            printf("%*c", row, ' ');
        }
        for (col = 0 + row; col < cols; ++col) {
            printf("%d", *(*(arr + row) + col));
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}