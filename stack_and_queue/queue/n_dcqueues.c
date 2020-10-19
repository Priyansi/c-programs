/*
Prtition an array to make n double circluar queues
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 3

typedef struct {
    int front;
    int rear;
} DCQUEUE;

int adjusted_ind(int q_ind) {
    return MAX * q_ind;
}

int enqueue(int* data, DCQUEUE* ndcq, int q_ind, int val, char end) {
    printf("%d %d\n", ndcq[0].front, ndcq[0].rear);
    if (ndcq[q_ind].front - adjusted_ind(q_ind) == (ndcq[q_ind].rear + 1) % MAX) {
        printf("DCQUEUE Overflow\n");
        return 1;
    }
    if (ndcq[q_ind].rear = -1) {
        ndcq[q_ind].front = ndcq[q_ind].rear = adjusted_ind(q_ind);
        ndcq[q_ind].rear = val;
    } else if (end == 'f') {
        ndcq[q_ind].front = (ndcq[q_ind].front + MAX - 1) % MAX + adjusted_ind(q_ind);
        ndcq[q_ind].front = val;
    } else {
        ndcq[q_ind].rear = (ndcq[q_ind].rear + 1) % MAX + adjusted_ind(q_ind);
        ndcq[q_ind].rear = val;
    }
    printf("%d %d\n", ndcq[0].front, ndcq[0].rear);
    return 0;
}

int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);
    int* data = (int*)malloc(n * MAX * sizeof(int));
    DCQUEUE* ndcq = (DCQUEUE*)malloc(n * sizeof(DCQUEUE));
    for (int i = 0; i < n; ++i) {
        ndcq[i].front = ndcq[i].rear = -1;
    }
    enqueue(data, ndcq, 0, 1, 'r');
    //enqueue(data, ndcq, 0, 2, 'r');
    return 0;
}