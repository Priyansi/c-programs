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

void disp(STACK* s) {
    if (s->top == NULL) {
        printf("NULL");
        return;
    }

    struct node* del;
    pop(s, &del);
    printf("%d->", del->data);
    disp(s);
    push(s, del->data);
}

void sort_insert(STACK* s, int val) {
    STACK temp;
    struct node* del;
    temp.top = NULL;
    while (1) {
        if (s->top == NULL) {
            push(s, val);
            break;
        }
        pop(s, &del);
        if (del->data > val) {
            push(s, del->data);
            push(s, val);
            break;
        } else {
            push(&temp, del->data);
        }
    }
    while (temp.top != NULL) {
        pop(&temp, &del);
        push(s, del->data);
    }
}

int main(int argc, char* argv[]) {
    STACK s;
    s.top = NULL;
    struct node* del;
    sort_insert(&s, 5);
    sort_insert(&s, 7);
    sort_insert(&s, 3);
    sort_insert(&s, 1);
    sort_insert(&s, 8);
    sort_insert(&s, 6);
    disp(&s);
    return 0;
}