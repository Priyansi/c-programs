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

void max_tree_recr(struct node* root) {
    if (root->right == NULL) {
        printf("%d\n", root->data);
        return;
    }
    max_tree_recr(root->right);
}

void max_tree_iter(struct node* root) {
    struct node* curr = root;
    if (curr != NULL) {
        while (curr->right != NULL) {
            curr = curr->right;
        }
        printf("%d\n", curr->data);
    }
}

void min_tree_recr(struct node* root) {
    if (root->left == NULL) {
        printf("%d\n", root->data);
        return;
    }
    max_tree_recr(root->left);
}

void min_tree_iter(struct node* root) {
    struct node* curr = root;
    if (curr != NULL) {
        while (curr->left != NULL) {
            curr = curr->left;
        }
        printf("%d\n", curr->data);
    }
}

int main(int argc, char* argv[]) {
    struct node* root = NULL;
    root = create(15);
    root->left = create(13);
    root->left->left = create(4);
    root->left->right = create(14);
    root->right = create(22);
    root->right->left = create(19);
    root->right->left->left = create(18);
    max_tree_iter(root);
    max_tree_recr(root);
    min_tree_iter(root);
    min_tree_iter(root);
    return 0;
}