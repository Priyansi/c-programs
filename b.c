#include <stdio.h>

int main() {
    extern int j;
    extern void count();
    count();
    count();
    printf("\n%d\n", j);
    return 0;
}