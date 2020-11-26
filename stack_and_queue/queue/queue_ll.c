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

int enqueue(QUEUE* q, int val) {
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

int dequeue(QUEUE* q, struct node** del) {
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

struct node* get_front(QUEUE q) {
    return q.front;
}

int is_empty(QUEUE q) {
    return q.front == NULL;
}

void display(QUEUE q) {
    if (q.front == NULL) {
        return;
    }
    for (struct node* curr = q.front; curr != NULL; curr = curr->next) {
        printf("%d->", curr->data);
    }
    printf("END\n");
}

int main(int argc, char* argv[]) {
    QUEUE q;
    q.front = q.rear = NULL;

    // inserting a random element is the queue
    int val = random() % 10;
    if (enqueue(&q, val) != 0) {
        printf("Queue Overflow\n");
    } else {
        printf("%d inserted successfully\n", val);
    }

    // enqueueing two more random elements
    val = random() % 10;
    enqueue(&q, val);

    val = random() % 10;
    enqueue(&q, val);

    // displaying our current queue
    display(q);

    struct node* del;
    // dequeueing an element
    if (dequeue(&q, &del) != 0) {
        printf("Queue Underflow\n");
    } else {
        printf("%d deleted successfully\n", del->data);
    }

    // displaying our current queue
    display(q);

    //getting the front element from the queue
    printf("%d is the front of the queue\n", get_front(q)->data);

    // dequeuing two more elements
    dequeue(&q, &del);
    dequeue(&q, &del);

    // now the queue has 0 elements so it won't be able to delete further
    if (dequeue(&q, &del) != 0) {
        printf("Queue Underflow\n");
    } else {
        printf("%d deleted successfully\n", del->data);
    }

    // checking if queue is empty
    printf("Is queue empty? : ");
    if (is_empty(q)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
