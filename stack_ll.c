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

void reverse(STACK* s) {
    if (s->top == NULL) {
    }
}

void disp_iter(STACK* s) {
    STACK temp;
    struct node* del;
    temp.top = NULL;
    while (s->top != NULL) {
        pop(s, &del);
        printf("%d->", del->data);
        push(&temp, del->data);
    }
    while (temp.top != NULL) {
        pop(&temp, &del);
        push(s, del->data);
    }
}

void disp_recr(STACK* s) {
    if (s->top == NULL) {
        printf("NULL");
        return;
    }

    struct node* del;
    pop(s, &del);
    printf("%d->", del->data);
    disp_recr(s);
    push(s, del->data);
}

void copy_iter(STACK* s, STACK* copy_s) {
    struct node* del;
    STACK temp;
    temp.top = NULL;
    while (s->top != NULL) {
        pop(s, &del);
        push(&temp, del->data);
    }
    while (temp.top != NULL) {
        pop(&temp, &del);
        push(copy_s, del->data);
    }
}

void copy_recr(STACK* s, STACK* copy_s) {
    if (s->top == NULL) {
        return;
    }
    struct node* del;
    pop(s, &del);
    copy_recr(s, copy_s);
    push(s, del->data);
    push(copy_s, del->data);
}

int main(int argc, char* argv[]) {
    STACK s;
    s.top = NULL;
    int val = random() % 10;
    if (push(&s, val) != 0) {
        printf("Stack Overflow");
    } else {
        printf("%d inserted successfully\n", val);
    }
    /*struct node* del;
    if (pop(&s, &del) != 0) {
        printf("Stack Underflow");
    } else {
        printf("%d deleted successfully\n", del->data);
    }*/
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    STACK copy_s;
    copy_s.top = NULL;
    copy_iter(&s, &copy_s);
    disp_iter(&copy_s);
    disp_iter(&s);
    return 0;
}