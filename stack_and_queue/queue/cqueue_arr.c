#include <stdio.h>
#include <stdlib.h>

#define MAX 3

typedef struct {
    int data[MAX];
    int front;
    int rear;
} CQUEUE;

int enqueue(CQUEUE* cq, int val) {
    if (cq->front == (cq->rear + 1) % MAX) {
        return 1;
    }
    if (cq->front == -1) {
        cq->front = 0;
    }
    cq->rear = (cq->rear + 1) % MAX;
    cq->data[cq->rear] = val;
    return 0;
}

int dequeue(CQUEUE* cq, int* del) {
    if (cq->front == -1) {
        return 1;
    }
    *del = cq->data[cq->front];
    if (cq->front == cq->rear) {
        cq->front = cq->rear = -1;
    } else {
        cq->front = (cq->front + 1) % MAX;
    }
    return 0;
}

int main(int argc, char* argv[]) {
    CQUEUE cq;
    cq.front = cq.rear = -1;
    int val = random() % 10;
    if (enqueue(&cq, val) != 0) {
        printf("CQUEUE Overflow\n");
    } else {
        printf("%d inserted successfully\n", val);
    }

    int del;
    if (dequeue(&cq, &del) != 0) {
        printf("CQUEUE Underflow\n");
    } else {
        printf("%d deleted successfully\n", del);
    }
    return 0;
}