#include <stdio.h>
#include <stdlib.h>

int main() {
    int A[6] = {1, 2, 3, 4, 5, 6};
    int(*P)[6] = &A;
    for (int i = 0; i < 3; ++i) {
        printf("%d ", P[0][i]);
    }
    printf("\n");
    return 0;
}