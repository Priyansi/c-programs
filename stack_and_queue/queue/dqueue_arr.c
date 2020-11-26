#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int data[MAX];
    int front;
    int rear;
} DQUEUE;

int insert(DQUEUE* dq, int val, char end) {
    if (dq->rear == MAX - 1) {
        printf("DQUEUE Overflow\n");
        return 1;
    }
    if (dq->rear == -1) {
        dq->front = dq->rear = 0;
        dq->data[dq->rear] = val;
    } else if (end == 'f') {
        if (dq->front == 0) {
            for (int i = dq->rear; i >= dq->front; --i) {
                dq->data[i + 1] = dq->data[i];
            }
            ++dq->rear;
        } else {
            --dq->front;
        }
        dq->data[dq->front] = val;
    } else {
        ++dq->rear;
        dq->data[dq->rear] = val;
    }
    return 0;
}

int delete (DQUEUE* dq, int* del, char end) {
    if (dq->front == -1) {
        printf("DQUEUE Underflow\n");
        return 1;
    }
    if (dq->front == dq->rear) {
        *del = dq->data[dq->front];
        dq->front = dq->rear = -1;
    } else if (end == 'f') {
        *del = dq->data[dq->front];
        ++dq->front;
    } else {
        *del = dq->data[dq->rear];
        --dq->rear;
    }
    return 0;
}

void display(DQUEUE dq) {
    if (dq.front == -1) {
        return;
    }
    for (int i = dq.front; i <= dq.rear; ++i) {
        printf("%d ", dq.data[i]);
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    DQUEUE dq;
    dq.front = dq.rear = -1;
    insert(&dq, 3, 'f');
    insert(&dq, 4, 'f');

    int del;
    delete (&dq, &del, 'r');
    display(dq);
    return 0;
}