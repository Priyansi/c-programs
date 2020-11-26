#include <stdio.h>
#include <stdlib.h>

int fact(int num) {
    if (num == 1) {
        return 1;
    }
    return num * fact(num - 1);
}

int main(int argc, char* argv[]) {
    int num = atoi(argv[1]);
    printf("%d\n", fact(num));
    return 0;
}