#include <stdio.h>
#include <stdlib.h>

void move_one(int num, char from_rod, char to_rod) {
    printf("Moving %d from %c to %c\n", num, from_rod, to_rod);
}

void tower_of_hanoi(int num, char from_rod, char temp_rod, char to_rod) {
    if (num == 0) {
        return;
    }
    tower_of_hanoi(num - 1, from_rod, to_rod, temp_rod);  // moving n-1 disks from from_rod to temp_rod
    move_one(num, from_rod, to_rod);
    tower_of_hanoi(num - 1, temp_rod, from_rod, to_rod);  // moving n-1 disks from temp_rod to to_rod
}

int main(int argc, char* argv[]) {
    int num = atoi(argv[1]);
    tower_of_hanoi(num, 'A', 'B', 'C');
    return 0;
}