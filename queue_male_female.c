#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int data[MAX];
    int front;
    int rear;
} QUEUE;

typedef struct {
    QUEUE male;
    QUEUE female;
} QMF;

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

void insert_male_female(QMF* q, int val, int type) {
    if (type == 0) {
        insert(&(q->male), val);
    } else {
        insert(&(q->female), val);
    }
}

void delete_male_female(QMF* q, int* last_delete) {
    int del, is_success;
    if (*last_delete == -1) {
        *last_delete = 0;
    }
    if (*last_delete == 0) {
        if (delete (&(q->male), &del) != 0) {
            if (delete (&(q->female), &del) != 0) {
                printf("Both queues empty\n");
            } else {
                *last_delete = 0;
            }
        } else {
            *last_delete = 1;
        }
    } else {
        if (delete (&(q->female), &del) != 0) {
            if (delete (&(q->male), &del) != 0) {
                printf("Both queues empty\n");
            } else {
                *last_delete = 1;
            }
        } else {
            *last_delete = 0;
        }
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
int display_male_female(QMF* q) {
    printf("Male - \n");
    display(&(q->male));
    printf("Female - \n");
    display(&(q->female));
}

int main(int argc, char* argv[]) {
    QMF q;
    q.male.front = q.male.rear = q.female.front = q.female.rear = -1;
    int last_delete = -1;
    insert_male_female(&q, 1, 0);
    insert_male_female(&q, 2, 0);
    display_male_female(&q);
    delete_male_female(&q, &last_delete);
    delete_male_female(&q, &last_delete);
    delete_male_female(&q, &last_delete);
    display_male_female(&q);
    return 0;
}