#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int rows1 = atoi(argv[1]);
    int cols1 = atoi(argv[2]);
    int rows2 = atoi(argv[3]);
    int cols2 = atoi(argv[4]);
    if (rows1 == rows2 && cols1 == cols2) {
        int row, col;
        int** arr1 = (int**)calloc(rows1, sizeof(int*));
        int** arr2 = (int**)calloc(rows1, sizeof(int*));
        int** arr3 = (int**)calloc(rows1, sizeof(int*));
        for (row = 0; row < rows1; ++row) {
            arr1[row] = (int*)calloc(cols1, sizeof(int));
            for (col = 0; col < cols1; ++col) {
                scanf("%d", &arr1[row][col]);
            }
        }
        for (row = 0; row < rows1; ++row) {
            arr2[row] = (int*)calloc(cols1, sizeof(int));
            for (col = 0; col < cols1; ++col) {
                scanf("%d", &arr2[row][col]);
            }
        }

        for (row = 0; row < rows1; ++row) {
            arr3[row] = (int*)calloc(cols1, sizeof(int));
            for (col = 0; col < cols1; ++col) {
                arr3[row][col] = arr1[row][col] + arr2[row][col];
            }
        }
        printf("Resultant array - \n");

        for (row = 0; row < rows1; ++row) {
            for (col = 0; col < cols1; ++col) {
                printf("%d ", arr3[row][col]);
            }
            printf("\n");
        }
        printf("\n");
    } else {
        printf("Arrays can't be added.\n");
    }
    return 0;
}