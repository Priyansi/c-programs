#pragma once

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
