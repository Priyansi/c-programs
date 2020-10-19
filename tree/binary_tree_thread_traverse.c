#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* left;
    int data;
    struct node* right;
    int rt;
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

struct node* create(int val) {
    struct node* curr = (struct node*)malloc(sizeof(struct node));
    curr->data = val;
    curr->rt = 0;
    curr->left = curr->right = NULL;
    return curr;
}

void traverse(struct node* root) {
    STACK s;
    s.top = NULL;
    struct node* del;
    push(&s, root);
    while (!is_empty(s)) {
        pop(&s, &del);
        printf("%d ", del->data);
        if (del->right != NULL) {  // right is pushed first because left should be popped first and therefore on top
            push(&s, del->right);
        }
        if (del->left != NULL) {
            push(&s, del->left);
        }
    }
}

int main(int argc, char* argv[]) {
    struct node* root = NULL;
    root = create(1);
    root->left = create(3);
    root->left->left = create(4);
    root->left->right = create(5);
    root->left->right->right = create(6);
    root->right = create(7);
    root->right->left = create(8);
    root->right->right = create(9);
    root->right->right->left = create(10);
    traverse(root);
    printf("\n");

    return 0;
}