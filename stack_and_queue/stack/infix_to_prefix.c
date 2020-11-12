#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char reverse_brace(char ch) {
    if (is_opening_brace(ch)) {
        return ')';
    } else {
        return '(';
    }
}

int is_brace(char ch) {
    return ch == '(' || ch == ')';
}

void reverse_string(char* str) {
    char temp;
    int i, j;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        if (is_brace(str[i])) {
            str[i] = reverse_brace(str[i]);
        }
        if (is_brace(str[j])) {
            str[j] = reverse_brace(str[j]);
        }
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
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

int priority_val(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return 0;
}

int is_high_to_low_priority(char op1, char op2) {
    if (priority_val(op1) > priority_val(op2)) {
        return 1;
    }
    return 0;
}

void infix_to_prefix(char* infix, char* prefix) {
    int i, j;
    i = j = 0;
    STACK s;
    s.top = -1;
    int del;

    reverse_string(infix);

    while (infix[i] != '\0') {
        if (is_operator(infix[i])) {
            if (is_opening_brace(infix[i])) {
                push(&s, infix[i]);
            } else if (is_closing_brace(infix[i])) {
                pop(&s, &del);
                while (!is_opening_brace(del)) {
                    prefix[j++] = del;
                    pop(&s, &del);
                }
            } else {
                if (s.top == -1) {
                    push(&s, infix[i]);
                } else {
                    pop(&s, &del);
                    if (is_high_to_low_priority(del, infix[i])) {
                        prefix[j++] = del;  // pushing deleted operator to our final answer
                        --i;                // checking if the now previous operator complies with the current operator
                    } else {
                        push(&s, del);       // pushing back removed operator since stack will remain same
                        push(&s, infix[i]);  // pushing current operator in the stack
                    }
                }
            }
        } else {
            prefix[j++] = infix[i];  // pushing operands to our final answer
        }
        ++i;
    }

    while (s.top != -1) {
        pop(&s, &del);
        prefix[j++] = del;
    }

    reverse_string(prefix);
}

int main(int argc, char* argv[]) {
    char infix[100], prefix[100];
    scanf("%[^\n]%*c", infix);
    infix_to_prefix(infix, prefix);
    printf("Prefix : %s\n", prefix);
    return 0;
}