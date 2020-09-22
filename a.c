#include <stdio.h>

static int j = 1;

void count() {
    static int i = 1;
    printf("%d in a", ++i);
}