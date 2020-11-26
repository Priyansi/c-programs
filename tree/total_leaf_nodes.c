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

struct node* insert_node(struct node* root, int val) {
    if (root == NULL) {
        root = create_node(val);
    } else if (root->data > val) {
        root->left = insert_node(root->left, val);
    } else {
        root->right = insert_node(root->right, val);
    }
    return root;
}

int total_leaf_nodes(struct node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return total_leaf_nodes(root->left) + total_leaf_nodes(root->right);
}

int main(int argc, char* argv[]) {
    struct node* root = NULL;
    root = insert_node(root, 4);
    root = insert_node(root, 6);
    root = insert_node(root, 2);
    root = insert_node(root, 1);
    root = insert_node(root, 3);
    root = insert_node(root, 5);
    printf("Total Leaf Nodes : %d\n", total_leaf_nodes(root));
    return 0;
}