#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int data[MAX];
    int front;
    int rear;
} DCQUEUE;

int enqueue(DCQUEUE* dcq, int val, char end) {
    if (dcq->front == (dcq->rear + 1) % MAX) {
        printf("DCQUEUE Overflow\n");
        return 1;
    }
    if (dcq->rear == -1) {
        dcq->front = dcq->rear = 0;
        dcq->data[dcq->rear] = val;
    } else if (end == 'f') {
        dcq->front = (dcq->front + MAX - 1) % MAX;
        dcq->data[dcq->front] = val;
    } else {
        dcq->rear = (dcq->rear + 1) % MAX;
        dcq->data[dcq->rear] = val;
    }
    return 0;
}

int dequeue(DCQUEUE* dcq, int* del, char end) {
    if (dcq->front == -1) {
        printf("DCQUEUE Underflow\n");
        return 1;
    }
    if (dcq->front == dcq->rear) {
        *del = dcq->data[dcq->front];
        dcq->front = dcq->rear = -1;
    } else if (end == 'f') {
        *del = dcq->data[dcq->front];
        dcq->front = (dcq->front + 1) % MAX;
    } else {
        *del = dcq->data[dcq->rear];
        dcq->rear = (dcq->rear + MAX - 1) % MAX;
    }
    return 0;
}

void display(DCQUEUE dcq) {
    if (dcq.front == -1) {
        return;
    }
    for (int i = dcq.front; i != (dcq.rear + 1) % MAX; i = (i + 1) % MAX) {
        printf("%d ", dcq.data[i]);
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    DCQUEUE dcq;
    dcq.front = dcq.rear = -1;
    enqueue(&dcq, 3, 'f');
    enqueue(&dcq, 4, 'f');
    enqueue(&dcq, 5, 'f');

    int del;
    dequeue(&dcq, &del, 'f');
    display(dcq);
    return 0;
}