#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

typedef struct {
    struct node* front;
    struct node* rear;
} QUEUE;

int insert(QUEUE* q, int val) {
    struct node* curr;
    curr = (struct node*)malloc(sizeof(struct node));
    if (curr == NULL) {
        return 1;
    }
    curr->data = val;
    curr->next = NULL;
    if (q->front == NULL) {
        q->front = q->rear = curr;
    } else {
        q->rear->next = curr;
        q->rear = curr;
    }
    return 0;
}

int delete (QUEUE* q, struct node** del) {
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
}

int main(int argc, char* argv[]) {
    QUEUE q;
    q.front = q.rear = NULL;
    int val = random() % 10;
    if (insert(&q, val) != 0) {
        printf("Queue Overflow\n");
    } else {
        printf("%d inserted successfully\n", val);
    }

    struct node* del;
    if (delete (&q, &del) != 0) {
        printf("Queue Underflow\n");
    } else {
        printf("%d deleted successfully\n", del->data);
    }
    return 0;
}