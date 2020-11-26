#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data;
    int pos;
    struct node* next;
};

typedef struct {
    struct node* top;
} STACK;

int push(STACK* s, int val, int i) {
    struct node* curr;
    curr = (struct node*)malloc(sizeof(struct node));
    if (curr == NULL) {
        return 1;
    }
    curr->data = val;
    curr->pos = i;
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
    s.top = NULL;
    struct node* del;
    while (infix[i] != '\0') {
        if (is_closing_brace(infix[i])) {
            pop(&s, &del);
            if (is_opening_brace(del->data)) {
                memmove(&infix[i], &infix[i + 1], strlen(infix) - i);
                memmove(&infix[del->pos], &infix[del->pos + 1], strlen(infix) - del->pos);
                return;
            } else {
                while (!(is_opening_brace(del->data))) {
                    pop(&s, &del);
                }
            }
        } else {
            push(&s, infix[i], i);
        }
        ++i;
    }
    printf("Duplicate brackets not found.\n");
}

int main(int argc, char* argv[]) {
    char infix[100];
    scanf("%[^\n]%*c", infix);
    find_dupli_brackets(&infix);
    printf("%s\n", infix);
    return 0;
}