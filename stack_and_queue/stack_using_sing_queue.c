#include <stdio.h>
#include <stdlib.h>

#include "../header_files/queue_ll.h"

// max capacity of stack is 5
typedef struct {
    QUEUE q;
} STACK;

int is_queue_empty(QUEUE q) {
    return q.front == NULL;
}

int push(STACK *s, int val) {
    if (enqueue(&s->q, val) != 0) {
        printf("STACK Overflow\n");
        return 1;
    }
    return 0;
}

struct node *pop_recursive(STACK *s, struct node *del) {
    dequeue(&s->q, &del);
    if (is_queue_empty(s->q)) {
        return del;
    }
    struct node *popped_ele = pop_recursive(s, del);
    push(s, del->data);
    return popped_ele;
}

int pop(STACK *s, struct node **del) {
    if (is_queue_empty(s->q)) {
        printf("STACK Underflow\n");
        return 1;
    }
    struct node *pop_recursive(STACK *, struct node *);
    *del = pop_recursive(s, *del);
    return 0;
}

int main(int argc, char *argv[]) {
    STACK s;
    s.q.front = s.q.rear = NULL;
    struct node *del;
    push(&s, 1);
    push(&s, 2);
    pop(&s, &del);
    printf("%d\n", del->data);
    return 0;
}