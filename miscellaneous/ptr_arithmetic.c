#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int num = atoi(argv[1]);
    char* num_ptr = &num;
    int pos;
    char* arr;
    for (pos = 0; pos < sizeof(int); ++pos) {
        printf("%p ", num_ptr + pos);
        arr[pos] = num_ptr + pos;
    }
    printf("\n");
    char** num_num_ptr = arr;
    for (pos = 0; pos < sizeof(int); ++pos) {
        printf("%p ", num_num_ptr + pos);
    }
    return 0;
}