#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int num = atoi(argv[1]);
    char* num_ptr = &num;
    int mid = sizeof(int) / 2;
    int temp;
    temp = *(num_ptr + mid);
    *(num_ptr + mid) = *(num_ptr + mid - 1);
    *(num_ptr + mid - 1) = temp;
    printf("%d,", num);
    return 0;
}