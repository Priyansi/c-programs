#include <stdio.h>
#include <stdlib.h>

#include "../header_files/queue_arr.h"

// max capacity of stack is 5
typedef struct {
    QUEUE q[2];
    int curr_q;
} STACK;

int is_queue_empty(QUEUE q) {
    return q.front == -1;
}

int push(STACK *s, int val) {
    if (insert(&s->q[s->curr_q], val) != 0) {
        printf("STACK Overflow\n");
        return 1;
    }
    return 0;
}

int pop(STACK *s, int *del) {
    if (is_queue_empty(s->q[s->curr_q])) {
        printf("STACK Underflow\n");
        return 1;
    }
    while (1) {
        delete_static(&s->q[s->curr_q], del);
        if (is_queue_empty(s->q[s->curr_q])) {
            s->curr_q = !s->curr_q;
            break;
        }
        insert(&s->q[!s->curr_q], *del);
    }
    return 0;
}

int main(int argc, char *argv[]) {
    STACK s;
    s.q[0].front = s.q[0].rear = s.q[1].front = s.q[1].rear = -1;
    s.curr_q = 0;
    int del;
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    push(&s, 5);
    push(&s, 6);
    pop(&s, &del);
    printf("%d\n", del);
    pop(&s, &del);
    pop(&s, &del);
    pop(&s, &del);
    pop(&s, &del);
    pop(&s, &del);
    return 0;
}