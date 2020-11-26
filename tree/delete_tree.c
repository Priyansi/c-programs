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

struct node* delete_tree(struct node* root) {
    if (root != NULL) {
        if (root->left != NULL || root->right != NULL) {
            root->left = delete_tree(root->left);
            root->right = delete_tree(root->right);
        }
        free(root);
        root = NULL;
    }
    return root;
}

int main(int argc, char* argv[]) {
    struct node* root = NULL;
    root = insert_node(root, 4);
    root = insert_node(root, 6);
    root = insert_node(root, 2);
    root = insert_node(root, 1);
    root = insert_node(root, 3);
    root = insert_node(root, 5);
    /*    
          4
        /   \
      2       6
     / \     /
    1   3   5
    */
    root = delete_tree(root);
    printf("%d", root->data);  // seg fault
    return 0;
}