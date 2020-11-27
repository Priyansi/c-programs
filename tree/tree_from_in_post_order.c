#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* left;
    int data;
    struct node* right;
};

struct node* create_node(int val) {
    struct node* curr = (struct node*)malloc(sizeof(struct node));
    curr->data = val;
    curr->left = curr->right = NULL;
    return curr;
}

void preorder_traverse(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder_traverse(root->left);
        preorder_traverse(root->right);
    }
}

void inorder_traverse(struct node* root) {
    if (root != NULL) {
        inorder_traverse(root->left);
        printf("%d ", root->data);
        inorder_traverse(root->right);
    }
}

void postorder_traverse(struct node* root) {
    if (root != NULL) {
        postorder_traverse(root->left);
        postorder_traverse(root->right);
        printf("%d ", root->data);
    }
}

int search(int* arr, int start_ind, int end_ind, int val) {
    for (int i = start_ind; i <= end_ind; ++i) {
        if (arr[i] == val) {
            return i;
        }
    }
    return -1;
}

struct node* construct_tree(int* inorder, int* postorder, int in_start_ind, int in_end_ind, int* post_curr_index) {
    if (in_start_ind > in_end_ind) {
        return NULL;
    }
    struct node* curr = create_node(postorder[(*post_curr_index)--]);
    if (in_start_ind == in_end_ind) {
        return curr;
    }
    int in_ind = search(inorder, in_start_ind, in_end_ind, curr->data);
    curr->right = construct_tree(inorder, postorder, in_ind + 1, in_end_ind, post_curr_index);
    curr->left = construct_tree(inorder, postorder, in_start_ind, in_ind - 1, post_curr_index);
    return curr;
}

int main(int argc, char* argv[]) {
    struct node* root = NULL;
    int inorder[] = {4, 3, 5, 6, 1, 8, 7, 10, 9};
    int postorder[] = {4, 6, 5, 3, 8, 10, 9, 7, 1};
    int size = sizeof(inorder) / sizeof(inorder[0]);
    int post_curr_ind = size - 1;
    root = construct_tree(inorder, postorder, 0, size - 1, &post_curr_ind);
    preorder_traverse(root);
    printf("\n");
    return 0;
}