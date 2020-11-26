#include <stdio.h>
#include <stdlib.h>

#include "../header_files/stack_ll.h"

// max capacity of queue is 5
typedef struct {
    STACK s;
} QUEUE;

int is_stack_empty(STACK s) {
    return s.top == NULL;
}

int enqueue(QUEUE* q, int val) {
    if (push(&q->s, val) != 0) {
        printf("QUEUE is full\n");
        return 1;
    }
    return 0;
}

struct node* dequeue_recursive(QUEUE* q, struct node* del) {
    pop(&q->s, &del);
    if (is_stack_empty(q->s)) {
        return del;
    }
    struct node* popped_ele = dequeue_recursive(q, del);
    push(&q->s, del->data);
    return popped_ele;
}

int dequeue(QUEUE* q, struct node** del) {
    if (is_stack_empty(q->s)) {
        printf("QUEUE is empty\n");
        return 1;
    }
    struct node* dequeue_recursive(QUEUE*, struct node*);
    *del = dequeue_recursive(q, *del);
    return 0;
}

int main(int argc, char* argv[]) {
    QUEUE q;
    q.s.top = NULL;
    struct node* del;
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    dequeue(&q, &del);
    printf("%d\n", del->data);
    return 0;
}