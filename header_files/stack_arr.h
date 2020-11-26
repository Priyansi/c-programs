#pragma once

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int data[MAX];
    int top;
} STACK;

int push(STACK* s, int val) {
    if (s->top == MAX - 1) {
        return 1;
    }
    s->top++;
    s->data[s->top] = val;
    return 0;
}

int pop(STACK* s, int* del) {
    if (s->top == -1) {
        return 1;
    }
    *del = s->data[s->top];
    s->top--;
    return 0;
}
