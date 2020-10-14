#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* left;
    int data;
    struct node* right;
};

struct node* create(int val) {
    struct node* curr = (struct node*)malloc(sizeof(struct node));
    curr->data = val;
    curr->left = curr->right = NULL;
    return curr;
}

void preorder_traverse(struct node* root) {
    if (root != NULL) {
        printf("%d->", root->data);
        preorder_traverse(root->left);
        preorder_traverse(root->right);
    }
}

void inorder_traverse(struct node* root) {
    if (root != NULL) {
        inorder_traverse(root->left);
        printf("%d->", root->data);
        inorder_traverse(root->right);
    }
}

void postorder_traverse(struct node* root) {
    if (root != NULL) {
        postorder_traverse(root->left);
        postorder_traverse(root->right);
        printf("%d->", root->data);
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
    inorder_traverse(root);
    printf("\n");
    preorder_traverse(root);
    printf("\n");
    postorder_traverse(root);
    printf("\n");
    return 0;
}