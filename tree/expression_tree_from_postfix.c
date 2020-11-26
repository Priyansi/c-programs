#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* left;
    char data;
    struct node* right;
};

struct node_stack {
    struct node* data;
    struct node_stack* next;
};

typedef struct {
    struct node_stack* top;
} STACK;

int push(STACK* s, struct node* val) {
    if (val == NULL) {
        return 1;
    }
    struct node_stack* curr;
    curr = (struct node_stack*)malloc(sizeof(struct node_stack));
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
    *del = s->top->data;
    s->top = s->top->next;
    return 0;
}

int is_empty(STACK s) {
    return s.top == NULL;
}

int is_operator(char ch) {
    char OPERATORS[] = "+-*/^\0";
    for (int i = 0; OPERATORS[i] != '\0'; ++i) {
        if (ch == OPERATORS[i]) {
            return 1;
        }
    }
    return 0;
}

struct node* create_node(char val) {
    struct node* curr = (struct node*)malloc(sizeof(struct node));
    curr->data = val;
    curr->left = curr->right = NULL;
    return curr;
}

void prefix_expression(struct node* root) {
    if (root != NULL) {
        printf("%c ", root->data);
        prefix_expression(root->left);
        prefix_expression(root->right);
    }
}

void infix_expression(struct node* root) {
    if (root != NULL) {
        infix_expression(root->left);
        printf("%c ", root->data);
        infix_expression(root->right);
    }
}

void postfix_expression(struct node* root) {
    if (root != NULL) {
        postfix_expression(root->left);
        postfix_expression(root->right);
        printf("%c ", root->data);
    }
}

struct node* construct_tree(struct node* root, char* postfix) {
    STACK s;
    s.top = NULL;
    struct node *curr, *op1, *op2;
    int i = 0;
    while (postfix[i] != '\0') {
        curr = create_node(postfix[i]);
        if (is_operator(postfix[i])) {
            pop(&s, &op1);
            pop(&s, &op2);
            curr->right = op1;
            curr->left = op2;
        }
        push(&s, curr);
        ++i;
    }
    pop(&s, &root);
    return root;
}

int main(int argc, char* argv[]) {
    struct node* root = NULL;
    char postfix[] = "ab/cde+f-g^/h*p/-k+";
    root = construct_tree(root, postfix);
    prefix_expression(root);
    printf("\n");
    infix_expression(root);
    printf("\n");
    postfix_expression(root);
    printf("\n");
    return 0;
}