#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int num = atoi(argv[1]);
    char* num_ptr = &num;
    int pos;
    for (pos = sizeof(int) - 1; pos >= 0; --pos) {
        printf("%d,", *(num_ptr + pos));
    }
    return 0;
}