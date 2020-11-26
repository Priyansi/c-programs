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

int search_iter(struct node* root, int val) {
    struct node* curr = root;
    while (curr != NULL) {
        if (curr->data == val) {
            return 1;
        } else if (curr->data > val) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    return 0;
}

int search_recr(struct node* root, int val) {
    if (root == NULL) {
        return 0;
    } else {
        if (root->data == val) {
            return 1;
        } else if (root->data > val) {
            return search_iter(root->left, val);
        } else {
            return search_iter(root->right, val);
        }
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
    int val;
    printf(search_iter(root, 14) ? "Found\n" : "Not found\n");
    printf(search_recr(root, 21) ? "Found\n" : "Not found\n");
    return 0;
}