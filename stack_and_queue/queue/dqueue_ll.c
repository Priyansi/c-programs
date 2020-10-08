#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

typedef struct {
    struct node* rear;
} DQUEUE;

int insert(DQUEUE* dq, int val, char end) {
    struct node* curr;
    curr = (struct node*)malloc(sizeof(struct node));
    if (curr == NULL) {
        printf("DQUEUE Overflow\n");
        return 1;
    }
    curr->data = val;
    curr->prev = curr->next = NULL;
    if (dq->rear == NULL) {
        curr->prev = curr->next = curr;
        dq->rear = curr;
    } else if (end == 'f') {
        curr->next = dq->rear->next;
        curr->prev = dq->rear;
        curr->next->prev = curr;
        dq->rear->next = curr;
    } else {
        curr->prev = dq->rear;
        printf("%d\n", curr->prev->data);
        curr->next = dq->rear->next;
        printf("%d\n", curr->next->data);
        dq->rear->prev = curr;
        printf("%d\n", dq->rear->prev->data);
        dq->rear->next->prev = curr;
        printf("%d\n", dq->rear->next->prev->data);
        dq->rear = curr;
        printf("%d\n", dq->rear->next->data);
    }
    return 0;
}

/*int delete (DQUEUE* q, struct node** del) {
    if (q->front == NULL) {
        return 1;
    }
    *del = q->front;
    if (q->front == q->rear) {
        q->front = q->rear = NULL;
    } else {
        q->front = q->front->next;
    }
    return 0;
}*/

void display(DQUEUE dq) {
    if (dq.rear == NULL) {
        return;
    }
    struct node* curr = dq.rear->next;
    for () {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    while (curr->next != dq.rear->next)
        ;
    printf("\n%d", curr->data);
}

int main(int argc, char* argv[]) {
    DQUEUE dq;
    dq.rear = NULL;
    insert(&dq, 3, 'f');
    insert(&dq, 2, 'r');
    //printf("%d %d\n", dq.rear->next->data, dq.rear->data);
    display(dq);
    return 0;
}