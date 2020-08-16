#include <stdio.h>

int main() {
    int* arrPtr;
    int arr[5];
    arrPtr = &arr[0];
    for (int pos = 0; pos < 5; ++pos) {
        scanf("%d", arrPtr + pos);
    }
    for (int pos = 0; pos < 5; ++pos) {
        printf("%d", arr[pos]);
    }
    return 0;
}