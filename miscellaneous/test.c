#include <stdio.h>
#include <stdlib.h>

int main() {
    const int arr[] = {1, 21, 3, 41, 15, 6, 17, 8};
    int *p, *q;

    p = &arr[0];
    q = p + 1;

    printf("p: %ld\nq: %ld\n", p, q);
    printf("%d\n", arr - q);
}

/*int main(int argc, char* argv[]) {
    int* a[2];
    a[0] = (int*)calloc(3, sizeof(int));
    a[1] = (int*)calloc(3, sizeof(int));
    int*(*b)[2] = &a[0];
    printf("%d", b[1][1]);
    return 0;
}*/