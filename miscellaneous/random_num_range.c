#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int start = atoi(argv[1]);
    int limit = atoi(argv[2]);
    printf("%ld", start + random() % (limit - start + 1));
    return 0;
}