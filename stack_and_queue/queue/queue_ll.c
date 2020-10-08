#include "../../header_files/queue_ll.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    QUEUE q;
    q.front = q.rear = NULL;
    int val = random() % 10;
    if (enqueue(&q, val) != 0) {
        printf("Queue Overflow\n");
    } else {
        printf("%d inserted successfully\n", val);
    }

    struct node* del;
    if (dequeue(&q, &del) != 0) {
        printf("Queue Underflow\n");
    } else {
        printf("%d deleted successfully\n", del->data);
    }
    return 0;
}