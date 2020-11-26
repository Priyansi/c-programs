#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char ch_to_int(char ch) {
    return ch - '0';
}

int is_operator(char ch) {
    char OPERATORS[] = "+-*/^()\0";
    for (int i = 0; OPERATORS[i] != '\0'; ++i) {
        if (ch == OPERATORS[i]) {
            return 1;
        }
    }
    return 0;
}

char eval(int a, char op, int b) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        case '^':
            return a ^ b;
    }
}

int postfix_eval(char* postfix) {
    STACK s;
    s.top = NULL;
    struct node *del1, *del2;
    int i, val;
    for (i = 0; i < strlen(postfix); ++i) {
        if (is_operator(postfix[i])) {
            pop(&s, &del1);
            pop(&s, &del2);
            push(&s, eval(del2->data, postfix[i], del1->data));
        } else {
            push(&s, ch_to_int(postfix[i]));
        }
    }
    struct node* del;
    pop(&s, &del);
    return del->data;
}

int main(int argc, char* argv[]) {
    char postfix[100];
    scanf("%[^\n]%*c", postfix);
    printf("%d", postfix_eval(&postfix));
    return 0;
}