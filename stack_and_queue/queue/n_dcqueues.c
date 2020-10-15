/*
Make n queues like this
---------->
<----------
---------->
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 2

typedef struct node {
    int data[MAX];
    int front;
    int rear;
    struct node* next;
    struct node* prev;
} QUEUE;

typedef struct {
    QUEUE* head;
} NQUEUES;

typedef struct {
    int data[MAX];
    int top;
} STACK;

int push(STACK* s, int val) {
    if (s->top == MAX - 1) {
        return 1;
    }
    s->top++;
    s->data[s->top] = val;
    return 0;
}

int pop(STACK* s, int* del) {
    if (s->top == -1) {
        return 1;
    }
    *del = s->data[s->top];
    s->top--;
    return 0;
}

int insert(QUEUE* q, int val) {
    if (q->rear == MAX - 1) {
        return 1;
    }
    if (q->front == -1) {
        q->front = q->rear = 0;
    } else {
        ++q->rear;
    }
    q->data[q->rear] = val;
    return 0;
}

int delete (QUEUE* q, int* del) {
    if (q->front == -1) {
        return 1;
    }
    *del = q->data[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        for (int i = q->front; i < q->rear; ++i) {
            q->data[i] = q->data[i + 1];
        }
        --q->rear;
    }
    return 0;
}

void reverse(QUEUE* q) {
    STACK s;
    s.top = -1;
    int del;
    while (q->front != -1) {
        delete (q, &del);
        push(&s, del);
    }
    while (s.top != -1) {
        pop(&s, &del);
        insert(q, del);
    }
}

void insert_nqueues(NQUEUES* nq, int val) {
    if (nq->head == NULL) {
        QUEUE* q = (QUEUE*)malloc(sizeof(QUEUE));
        q->front = q->rear = -1;
        q->next = q->prev = NULL;
        nq->head = q;
        insert(q, val);
    } else {
        QUEUE* curr = nq->head;
        for (curr; curr->next != NULL; curr = curr->next)
            ;
        if (insert(curr, val) != 0) {
            QUEUE* q = (QUEUE*)malloc(sizeof(QUEUE));
            q->front = q->rear = -1;
            q->next = NULL;
            q->prev = curr;
            curr->next = q;
            insert(q, val);
        }
    }
}

void delete_nqueues(NQUEUES* nq) {
    if (nq->head == NULL) {
        return;
    } else {
        int del;
        delete (nq->head, &del);
        QUEUE* curr = nq->head->next;
        for (curr; curr != NULL; curr = curr->next) {
            delete (curr, &del);
            insert(curr->prev, del);
            if (curr->front == -1) {
                curr->prev->next = NULL;
                free(curr);
            }
        }
    }
}

void display(QUEUE* q) {
    if (q->front == -1) {
        return;
    }
    for (int i = q->front; i <= q->rear; ++i) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

void display_nqueues(NQUEUES nq) {
    if (nq.head == NULL) {
        return;
    }
    int i = 0;
    for (nq.head, i; nq.head != NULL; nq.head = nq.head->next, ++i) {
        if (i & 1) {
            reverse(nq.head);
            display(nq.head);
            reverse(nq.head);
        } else {
            display(nq.head);
        }
    }
}

int main(int argc, char* argv[]) {
    NQUEUES nq;
    nq.head = NULL;
    insert_nqueues(&nq, 1);
    insert_nqueues(&nq, 2);
    insert_nqueues(&nq, 3);
    insert_nqueues(&nq, 4);
    insert_nqueues(&nq, 5);
    insert_nqueues(&nq, 6);
    display_nqueues(nq);
    delete_nqueues(&nq);
    delete_nqueues(&nq);
    display_nqueues(nq);
    return 0;
}