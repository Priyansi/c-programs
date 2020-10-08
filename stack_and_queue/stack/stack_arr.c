#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int data[MAX];
    int top;
} STACK;

typedef struct {
    int data[MAX];
    int top_left;
    int top_right;
} STACK_SIDE;

int push_side(STACK_SIDE* ss, int val, int side) {
    if (ss->top_left + 1 == ss->top_right) {
        return 1;
    }
    if (side) {
        ss->top_right--;
        ss->data[ss->top_right] = val;
    } else {
        ss->top_left++;
        ss->data[ss->top_left] = val;
    }
    return 0;
}

int push(STACK* s, int val) {
    if (s->top == MAX - 1) {
        return 1;
    }
    s->top++;
    s->data[s->top] = val;
    return 0;
}

int pop_side(STACK_SIDE* ss, int* del_ss, int side) {
    if (side) {
        if (ss->top_right == MAX) {
            return 1;
        }
        *del_ss = ss->data[ss->top_right];
        ss->top_right++;
    } else {
        if (ss->top_left == -1) {
            return 1;
        }
        *del_ss = ss->data[ss->top_left];
        ss->top_left--;
    }
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

int main(int argc, char* argv[]) {
    STACK s;
    s.top = -1;
    int val = random() % 10;
    if (push(&s, val) != 0) {
        printf("Stack Overflow\n");
    } else {
        printf("%d inserted successfully\n", val);
    }
    int del;
    if (pop(&s, &del) != 0) {
        printf("Stack Underflow\n");
    } else {
        printf("%d deleted successfully\n", del);
    }
    STACK_SIDE ss;
    ss.top_left = -1;
    ss.top_right = MAX;
    int val_ss = random() % 10;
    if (push_side(&ss, val_ss, 1) != 0) {
        printf("Stack Overflow\n");
    } else {
        printf("%d inserted successfully\n", val_ss);
    }
    int del_ss;
    if (pop_side(&ss, &del_ss, 1) != 0) {
        printf("Stack Underflow\n");
    } else {
        printf("%d deleted successfully\n", del_ss);
    }
    return 0;
}