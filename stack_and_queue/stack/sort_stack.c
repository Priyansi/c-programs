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

int is_empty(STACK s) {
    if (s.top == NULL) {
        return 1;
    }
    return 0;
}

void disp(STACK s) {
    if (s.top == NULL) {
        printf("NULL\n");
        return;
    }

    struct node* del;
    pop(&s, &del);
    printf("%d->", del->data);
    disp(s);
}

void sort_stack(STACK* s) {
    STACK temp;
    struct node *del1, *del2;
    temp.top = NULL;
    while (!is_empty(*s)) {
        pop(s, &del1);
        if (!is_empty(temp)) {
            pop(&temp, &del2);
            while (!is_empty(temp) && del2->data > del1->data) {
                push(s, del2->data);
                pop(&temp, &del2);
            }
            if (del2->data < del1->data) {
                push(&temp, del2->data);
                push(&temp, del1->data);
            } else {
                push(&temp, del1->data);
                push(&temp, del2->data);
            }

        } else {
            push(&temp, del1->data);
        }
    }
    while (!is_empty(temp)) {
        pop(&temp, &del1);
        push(s, del1->data);
    }
}

int main(int argc, char* argv[]) {
    STACK s;
    s.top = NULL;
    struct node* del;
    push(&s, 5);
    push(&s, 7);
    push(&s, 3);
    push(&s, 1);
    push(&s, 8);
    push(&s, 6);
    disp(s);
    sort_stack(&s);
    printf("After Sorting -\n");
    disp(s);
    return 0;
}