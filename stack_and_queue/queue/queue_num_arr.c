#include <stdio.h>
#include <stdlib.h>

#define MAX 10

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

int delete (QUEUE* q, int* del) {
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

int insert_nums(QUEUE* q, int val) {
    if (MAX - 1 - q->rear < val) {
        return 1;
    } else {
        for (int i = 0; i < val; ++i) {
            insert(q, val);
        }
    }
    return 0;
}

void delete_nums(QUEUE* q) {
    int num = q->data[q->front];
    int del;
    for (int i = 0; i < num; ++i) {
        delete (q, &del);
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

int main(int argc, char* argv[]) {
    QUEUE q;
    q.front = q.rear = -1;
    int val = random() % 10;
    if (insert_nums(&q, val) != 0) {
        printf("Queue Overflow\n");
    } else {
        printf("%d inserted successfully\n", val);
    }
    insert_nums(&q, 2);
    insert_nums(&q, 5);
    display(&q);
    delete_nums(&q);
    display(&q);
    return 0;
}