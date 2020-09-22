#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    char data[MAX];
    int top;
} STACK;

void push(STACK* s, int val) {
    s->top++;
    s->data[s->top] = val;
}

void pop(STACK* s, int* del) {
    *del = s->data[s->top];
    s->top--;
}

int is_opening_brace(char op) {
    return op == '(';
}

int is_closing_brace(char op) {
    return op == ')';
}

void find_improper_brackets(char* infix) {
    int i;
    i = 0;
    STACK s;
    s.top = -1;
    int del;
    while (infix[i] != '\0') {
        if (is_closing_brace(infix[i])) {
            if (s.top == -1) {
                printf("Improper brackets found.\n");
                return;
            }
            pop(&s, &del);
        } else if (is_opening_brace(infix[i])) {
            push(&s, infix[i]);
        }
        ++i;
    }
    if (s.top != -1) {
        printf("Improper brackets found.\n");
    } else {
        printf("Improper brackets not found.\n");
    }
}

int main(int argc, char* argv[]) {
    char infix[100];
    scanf("%[^\n]%*c", infix);
    find_improper_brackets(&infix);
    return 0;
}