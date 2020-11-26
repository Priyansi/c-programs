#pragma once

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int data[MAX];
    int front;
    int rear;
} QUEUE;

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

int delete_static(QUEUE* q, int* del) {
    if (q->front == -1) {
        return 1;
    }
    *del = q->data[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        ++q->front;
    }
    return 0;
}
int delete_shift(QUEUE* q, int* del) {
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
    }
    return 0;
}