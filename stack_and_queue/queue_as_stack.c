#include <stdio.h>
#include <stdlib.h>

#include "../header_files/stack_arr.h"

// max capacity of queue is 5 since it is made up of two stacks (one for insertion s[0] and one for deletion s[1]) of capacity 5 each
typedef struct {
    STACK s[2];
    int curr_s;
} QUEUE;

int is_stack_empty(STACK s) {
    return s.top == -1;
}

int enqueue(QUEUE* q, int val) {
    if (push(&q->s[0], val) != 0) {
        printf("QUEUE is full\n");
        return 1;
    }
    return 0;
}
int dequeue(QUEUE* q, int* del) {
    if (is_stack_empty(q->s[0]) && is_stack_empty(q->s[1])) {
        printf("QUEUE is empty\n");
        return 1;
    } else if (!is_stack_empty(q->s[1])) {
        pop(&q->s[1], del);
    } else {
        while (!is_stack_empty(q->s[0])) {
            pop(&q->s[0], del);
            push(&q->s[1], *del);
        }
        pop(&q->s[1], del);
    }
    return 0;
}

int main(int argc, char* argv[]) {
    QUEUE q;
    q.s[0].top = q.s[1].top = -1;
    q.curr_s = 0;
    int del;
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    enqueue(&q, 6);
    dequeue(&q, &del);
    printf("%d\n", del);
    dequeue(&q, &del);
    dequeue(&q, &del);
    dequeue(&q, &del);
    dequeue(&q, &del);
    dequeue(&q, &del);
    return 0;
}