#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

typedef struct {
    struct node* top;
} STACK;

int push(STACK* s, int val) {
    struct node* curr;
    curr = (struct node*)malloc(sizeof(struct node));
    if (curr == NULL) {
        return 1;
    }
    curr->data = val;
    curr->next = NULL;
    curr->next = s->top;
    s->top = curr;
    return 0;
}

int pop(STACK* s, struct node** del) {
    if (s->top == NULL) {
        return 1;
    }
    *del = s->top;
    s->top = s->top->next;
    return 0;
}

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

void sort_insert1(QUEUE* q, int val) {
    QUEUE temp;
    struct node* del = NULL;
    temp.front = temp.rear = NULL;
    while (1) {
        if (q->front == NULL) {
            insert(q, val);
            break;
        }
        delete (q, &del);
        if (del->data < val) {
        } else {
        }
    }
}

void sort_insert(QUEUE* q, int val) {
    QUEUE temp;
    struct node* del = NULL;
    temp.front = temp.rear = NULL;
    while (1) {
        if (q->front == NULL) {
            break;
        }
        delete (q, &del);
        if (del->data > val) {
            insert(q, val);
            while (q->front != NULL) {
                delete (q, &del);
                insert(&temp, del->data);
            }
            insert(&temp, del->data);
            break;
        } else {
            insert(&temp, del->data);
        }
    }
    while (temp.front != NULL) {
        insert(q, del->data);
        delete (&temp, &del);
    }
    insert(q, val);
}

void display(QUEUE q) {
    if (q.front == NULL) {
        return;
    }
    for (struct node* curr = q.front; curr != NULL; curr = curr->next) {
        printf("%d ", curr->data);
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    QUEUE q;
    q.front = q.rear = NULL;
    sort_insert(&q, 5);
    sort_insert(&q, 7);
    sort_insert(&q, 3);
    /*sort_insert(&q, 1);
    sort_insert(&q, 8);
    sort_insert(&q, 6);*/
    display(q);
    return 0;
}