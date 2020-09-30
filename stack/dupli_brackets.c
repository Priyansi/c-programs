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

void find_dupli_brackets(char* infix) {
    int i;
    i = 0;
    STACK s;
    s.top = -1;
    int del;
    while (infix[i] != '\0') {
        if (is_closing_brace(infix[i])) {
            pop(&s, &del);
            if (is_opening_brace(del)) {
                printf("Duplicate brackets found.\n");
                return;
            } else {
                while (!(is_opening_brace(del))) {
                    pop(&s, &del);
                }
            }
        } else {
            push(&s, infix[i]);
        }
        ++i;
    }
    printf("Duplicate brackets not found.\n");
}

int main(int argc, char* argv[]) {
    char infix[100];
    scanf("%[^\n]%*c", infix);
    find_dupli_brackets(&infix);
    return 0;
}