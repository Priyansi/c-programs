#include <stdio.h>
#include <stdlib.h>

// maximum size of the queue
#define MAX 3

typedef struct {
    int data[MAX];
    int front;
    int rear;
} CQUEUE;

int enqueue(CQUEUE* cq, int val) {
    // if circluar queue is full
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
    // if circular queue is empty
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

int get_front(CQUEUE cq) {
    return cq.data[cq.front];
}

int is_empty(CQUEUE cq) {
    return cq.front == -1;
}

void display(CQUEUE cq) {
    if (cq.front == -1) {
        return;
    }
    int i;
    for (i = cq.front; i <= cq.rear && i < MAX; ++i) {
        printf("%d->", cq.data[i]);
    }
    if (i == MAX) {
        i = 0;
        while (i <= cq.rear) {
            printf("%d->", cq.data[i]);
        }
    }
    printf("END\n");
}

int main(int argc, char* argv[]) {
    CQUEUE cq;
    cq.front = cq.rear = -1;

    // inserting a random element is the queue
    int val = random() % 10;
    if (enqueue(&cq, val) != 0) {
        printf("Queue Overflow\n");
    } else {
        printf("%d inserted successfully\n", val);
    }

    // enqueueing two more random elements
    val = random() % 10;
    enqueue(&cq, val);

    val = random() % 10;
    enqueue(&cq, val);

    // displaying our current queue
    display(cq);

    int del;
    // dequeueing an element
    if (dequeue(&cq, &del) != 0) {
        printf("Queue Underflow\n");
    } else {
        printf("%d deleted successfully\n", del);
    }

    // displaying our current queue
    display(cq);

    //getting the front element from the queue
    printf("%d is the front of the queue\n", get_front(cq));

    // dequeuing two more elements
    dequeue(&cq, &del);
    dequeue(&cq, &del);

    // now the queue has 0 elements so it won't be able to delete further
    if (dequeue(&cq, &del) != 0) {
        printf("Queue Underflow\n");
    } else {
        printf("%d deleted successfully\n", del);
    }

    // checking if queue is empty
    printf("Is queue empty? : ");
    if (is_empty(cq)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}