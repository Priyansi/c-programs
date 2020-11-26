#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int data[MAX];
    int priority[MAX];
    int front;
    int rear;
} PQUEUE;

int insert(PQUEUE* pq, int val, int p) {
    if (pq->rear == MAX - 1) {
        printf("PQUEUE Overflow\n");
        return 1;
    }
    if (pq->rear == -1) {
        pq->front = pq->rear = 0;
    } else {
        ++pq->rear;
    }
    pq->data[pq->rear] = val;
    pq->priority[pq->rear] = p;
    return 0;
}

int delete (PQUEUE* pq, int* del) {
    if (pq->front == -1) {
        printf("PQUEUE Underflow\n");
        return 1;
    }
    if (pq->front == pq->rear) {
        *del = pq->data[pq->front];
        pq->front = pq->rear = -1;
    } else {
        int i, lowest_priority = pq->front;
        for (i = pq->front + 1; i <= pq->rear; ++i) {
            if (pq->priority[i] < pq->priority[lowest_priority]) {
                lowest_priority = i;
            }
        }
        *del = pq->data[lowest_priority];
        for (i = lowest_priority; i < pq->rear; ++i) {
            pq->data[i] = pq->data[i + 1];
            pq->priority[i] = pq->priority[i + 1];
        }
        --pq->rear;
    }
    return 0;
}

void display(PQUEUE dq) {
    if (dq.front == -1) {
        return;
    }
    for (int i = dq.front; i <= dq.rear; ++i) {
        printf("%d-%d\t", dq.data[i], dq.priority[i]);
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    PQUEUE dq;
    int del;
    dq.front = dq.rear = -1;
    insert(&dq, 1, 4);
    insert(&dq, 2, 3);
    insert(&dq, 3, 5);
    delete (&dq, &del);
    display(dq);
    return 0;
}