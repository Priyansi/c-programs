// Program to to shift all even elements to one end and all odd ones to another in a randomly generated array given the size
#include <stdio.h>
#include <stdlib.h>

int arr[] = {4, 4, 4, 4, 3, 3, 3, 6, 6, 6, 6, 6, 6, 2, 2, 2, 2, 5, 5, 5, 5, 5};
int arr_len = 22;
void insert(int num, int pos) {
    int i;
    if (arr_len == 0) {
        for (i = 0; i < num; ++i) {
            arr[i] = num;
            ++arr_len;
        }
    } else if (pos < arr_len) {
        int curr_num = arr[pos];
        int curr_pos;
        int can_insert = 1;
        for (i = pos; i <= pos + num; ++i) {
            if (arr[i] != num) {
                can_insert = 0;
                curr_pos = i;
                break;
            }
        }
        if (can_insert) {
            for (i = arr_len - 1; i >= pos; ++i) {
                arr[i + num] = arr[i];
            }
            arr_len += num;
            for (i = 0; i < num; ++i) {
                arr[i + pos] = num;
            }
        } else {
            for (i = arr_len - 1; i >= curr_pos; ++i) {
                arr[i + num] = arr[i];
            }
            arr_len += num;
            for (i = 0; i < num; ++i) {
                arr[curr_pos + i] = num;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    insert(5, 0);
    for (int i = 0; i < arr_len; ++i) {
        printf("%d ", arr[i]);
    }
    return 0;
}