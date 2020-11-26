#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* left;
    int data;
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

struct node* create(int val) {
    struct node* curr = (struct node*)malloc(sizeof(struct node));
    curr->data = val;
    curr->left = curr->right = NULL;
    return curr;
}

void preorder_traverse(struct node* root) {
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

void inorder_traverse(struct node* root) {
    STACK s;
    s.top = NULL;
    struct node* curr_node = root;
    struct node* del;
    // start with the leftmost element
    while (curr_node != NULL) {
        push(&s, curr_node);
        curr_node = curr_node->left;
    }
    while (!is_empty(s)) {
        pop(&s, &del);  // pop the leftmost node
        printf("%d ", del->data);
        curr_node = del->right;      // if right doesn't exist, repeat loop to pop parent
        while (curr_node != NULL) {  // if right exists, it becomes the curr (root node) and again goes on left
            push(&s, curr_node);
            curr_node = curr_node->left;
        }
    }
}

void postorder_traverse(struct node* root) {
    STACK s;
    s.top = NULL;
    struct node* curr_node = root;
    struct node *del1, *del2;
    while (curr_node != NULL) {
        push(&s, curr_node->right);
        push(&s, curr_node);
        curr_node = curr_node->left;
    }
    while (!is_empty(s)) {
        pop(&s, &del1);
        if (del1->right == NULL) {
            printf("%d ", del1->data);
        } else if (is_empty(s)) {
            printf("%d ", del1->data);
        } else {
            pop(&s, &del2);
            if (del1->right == del2) {
                push(&s, del1);
                curr_node = del2;
                while (curr_node != NULL) {
                    push(&s, curr_node->right);
                    push(&s, curr_node);
                    curr_node = curr_node->left;
                }
            } else {
                push(&s, del2);
                printf("%d ", del1->data);
            }
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
    preorder_traverse(root);
    printf("\n");
    inorder_traverse(root);
    printf("\n");
    postorder_traverse(root);
    printf("\n");

    return 0;
}