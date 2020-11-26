#include <stdio.h>

int main() {
    int n;
    int* n_ptr = &n;
    int** n_n_ptr = &n_ptr;
    int*** n_n_n_ptr = &n_n_ptr;
    scanf("%d", n_ptr);  // using single pointer
    printf("%d\n", *n_ptr);
    scanf("%d", **n_n_n_ptr);  // using triple pointer
    printf("%d\n", ***n_n_n_ptr);
    return 0;
}