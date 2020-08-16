#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[2][3][4] = {{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}},
                        {{13, 14, 15, 16}, {17, 18, 19, 20}, {21, 22, 23, 24}}};
    printf("%p\n", arr);
    printf("%p\n", *arr);
    printf("%p\n", *(arr + 1));
    printf("%p\n", *(arr + 1) + 2);
    printf("%p %p\n", arr[0][2], *(*arr + 2));
    printf("%d\n", *(arr[1][2]));
    return 0;
}