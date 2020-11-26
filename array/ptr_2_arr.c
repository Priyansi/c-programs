#include <stdio.h>
#include <stdlib.h>

int main() {
    int A[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int(*p)[3] = A;
    int row, col;
    for (row = 0; row < 3; ++row) {
        for (col = 0; col < 4; ++col) {
            printf("%d ", *(*(p + row) + row + col));
        }
        printf("\n");
    }
    return 0;
}