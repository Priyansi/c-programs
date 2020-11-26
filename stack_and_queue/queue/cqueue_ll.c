#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

typedef struct {
    struct node* rear;
} CQUEUE;

int enqueue(CQUEUE* cq, int val) {
    struct node* curr;
    curr = (struct node*)malloc(sizeof(struct node));
    if (curr == NULL) {
        return 1;
    }
    curr->data = val;
    curr->next = NULL;
    if (cq->rear == NULL) {
        curr->next = curr;
        cq->rear = curr;
    } else {
        curr->next = cq->rear->next;
        cq->rear->next = curr;
        cq->rear = curr;
    }
    return 0;
}

int dequeue(CQUEUE* cq, int* del) {
    if (cq->rear == NULL) {
        return 1;
    }
    *del = cq->rear->next->data;
    if (cq->rear == cq->rear->next) {
        free(cq->rear);
        cq->rear = NULL;
    } else {
        struct node* ptr;
        ptr = cq->rear->next;
        cq->rear->next = cq->rear->next->next;
        free(ptr);
    }
    return 0;
}

void display(CQUEUE cq) {
    if (cq.rear == NULL) {
        return;
    }
    struct node* curr = cq.rear->next;
    for (curr; curr != cq.rear; curr = curr->next) {
        printf("%d ", curr->data);
    }
    printf("%d\n", curr->data);
}

int main(int argc, char* argv[]) {
    CQUEUE cq;
    cq.rear = NULL;
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