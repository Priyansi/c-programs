#include <stdio.h>
#include <stdlib.h>

struct temp {
    union t1 {
        char s[5];
        long z;
    };
    ,
        union t2 {
        float y;
        long z;
    };
} t, *p;

main() {
    printf("%ld  %ld\n", sizeof(t), sizeof(*p));
}

/*int main(int argc, char* argv[]) {
    int* a[2];
    a[0] = (int*)calloc(3, sizeof(int));
    a[1] = (int*)calloc(3, sizeof(int));
    int*(*b)[2] = &a[0];
    printf("%d", b[1][1]);
    return 0;
}*/