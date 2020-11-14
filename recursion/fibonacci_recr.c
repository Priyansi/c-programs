#include <stdio.h>
#include <stdlib.h>

int fib(int num) {
    printf("%d ", num);
    if (num == 0) {
        return 0;
    }
    if (num == 1) {
        return 1;
    }
    return fib(num - 2) + fib(num - 1);
}

int main(int argc, char* argv[]) {
    int num = atoi(argv[1]);
    printf("%d\n", fib(num));
    return 0;
}