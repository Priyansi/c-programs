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

void inorder_traverse(struct node* root) {
    if (root != NULL) {
        inorder_traverse(root->left);
        printf("%d ", root->data);
        inorder_traverse(root->right);
    }
}

int search(struct node* root, int val) {
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

struct node* get_max(struct node* root) {
    struct node* curr = root;
    if (curr != NULL) {
        while (curr->right != NULL) {
            curr = curr->right;
        }
        return curr;
    }
    return NULL;
}

struct node* get_min(struct node* root) {
    struct node* curr = root;
    if (curr != NULL) {
        while (curr->left != NULL) {
            curr = curr->left;
        }
        return curr;
    }
    return NULL;
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

int main(int argc, char* argv[]) {
    struct node* root = NULL;
    root = insert_node(root, 4);
    root = insert_node(root, 6);
    root = insert_node(root, 2);
    root = insert_node(root, 1);
    root = insert_node(root, 3);
    root = insert_node(root, 5);
    inorder_traverse(root);

    return 0;
}