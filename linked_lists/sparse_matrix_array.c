#include <stdio.h>
#include <stdlib.h>

void create(int** ptr, int row, int col, int val) {
    int i, j;
    // accepting values
    *(*(ptr + i) + 0) = row;
    *(*(ptr + i) + 1) = col;
    *(*(ptr + i) + 2) = val;
    for (i = 1; i < val + 1; ++i) {
        *(*(ptr + i) + 0) = random() % row;
        *(*(ptr + i) + 1) = random() % col;
        *(*(ptr + i) + 2) = random() % 20;
        printf("%d\n", *(*(ptr + i) + 0));
    }
}

void display_arr(int** ptr) {
    int val;
    int vals = *(*ptr + 2);
    for (val = 0; val < vals; ++val) {
        printf("%d %d %d\n", *(*(ptr + val) + 0), *(*(ptr + val) + 1), *(*(ptr + val) + 2));
    }
}

void display_matrix(int** ptr) {
    int row, col, pos;
    int rows = *(*ptr + 0), cols = *(*ptr + 1), vals = *(*ptr + 2);
    int flag;
    for (row = 0; row < rows; ++row) {
        for (col = 0; col < cols; ++col) {
            flag = 0;
            for (pos = 1; pos < vals; ++pos) {
                if (row == *(*(ptr + pos) + 0) && col == *(*(ptr + pos) + 1)) {
                    flag = 1;
                    break;
                }
            }
            printf("%d ", (flag) ? *(*(ptr + pos) + 2) : 0);
        }
        printf("\n");
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    int row = atoi(argv[1]);
    int col = atoi(argv[2]);
    int val = atoi(argv[3]);
    printf("hello");
    int** ptr = (int**)malloc((val + 1) * sizeof(int*));
    for (int i = 0; i < val + 1; ++i) {
        *(ptr + i) = (int*)malloc(3 * sizeof(int));
    }
    printf("hello");
    create(ptr, row, col, val);
    //display_arr(ptr);
    return 0;
}