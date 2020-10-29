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

struct node* create_node(int val) {
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
    printf("\n");
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
    printf("\n");
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
    printf("\n");
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

struct node* insert_node_recr(struct node* root, int val) {
    if (root == NULL) {
        root = create_node(val);
    } else if (root->data > val) {
        root->left = insert_node_recr(root->left, val);
    } else {
        root->right = insert_node_recr(root->right, val);
    }
    return root;
}

struct node* insert_node_iter(struct node* root, int val) {
    struct node* curr = root;
    struct node* parent;
    if (root == NULL) {
        root = create_node(val);
    } else {
        while (curr != NULL) {
            parent = curr;
            if (curr->data > val) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        if (parent->data > val) {
            parent->left = create_node(val);
        } else {
            parent->right = create_node(val);
        }
    }
    return root;
}

struct node* delete_node_recr(struct node* root, int val) {
    if (root != NULL) {
        if (root->data > val) {
            root->left = delete_node_recr(root->left, val);
        } else if (root->data < val) {
            root->right = delete_node_recr(root->right, val);
        } else {
            if (root->left != NULL && root->right != NULL) {
                struct node* left_tree_max = get_max(root->left);
                root->data = left_tree_max->data;
                root->left = delete_node_recr(root->left, root->data);
            } else if (root->left == NULL && root->right == NULL) {
                free(root);
                root = NULL;
            } else {
                struct node* child_node;
                if (root->left != NULL) {
                    child_node = root->left;
                } else {
                    child_node = root->right;
                }
                free(root);
                return child_node;
            }
        }
    }
    return root;
}

struct node* delete_node_iter(struct node* root, int val) {
    if (root != NULL) {
        struct node* curr = root;
        struct node *parent, *child;
        while (curr->data != val) {
            parent = curr;
            if (curr->data > val) {
                curr = curr->left;
            } else if (curr->data < val) {
                curr = curr->right;
            }
        }
        if (curr->left != NULL && curr->right != NULL) {
            child = get_max(curr->left);  // replace with max from left subtree
            curr->data = child->data;
            val = child->data;  // child is to be deletec so val changed
            parent = curr;      // if parent == val then we delete
            curr = curr->left;
            while (curr->data != val) {
                parent = curr;
                if (curr->data > val) {
                    curr = curr->left;
                } else if (curr->data < val) {
                    curr = curr->right;
                }
            }
        }
        if (curr->left == NULL && curr->right == NULL) {
            child = NULL;
        } else if (curr->left != NULL) {
            child = curr->left;
        } else {
            child = curr->right;
        }

        if (parent->data >= val) {
            parent->left = child;
        } else {
            parent->right = child;
        }
        free(curr);
    }
    return root;
}

int main(int argc, char* argv[]) {
    struct node* root = NULL;
    root = insert_node_iter(root, 4);
    root = insert_node_iter(root, 6);
    root = insert_node_iter(root, 2);
    root = insert_node_iter(root, 1);
    root = insert_node_iter(root, 3);
    root = insert_node_iter(root, 5);
    inorder_traverse(root);

    root = delete_node_iter(root, 2);  // two children
    inorder_traverse(root);

    root = delete_node_iter(root, 6);  // one child
    inorder_traverse(root);

    root = delete_node_iter(root, 5);  // no child
    inorder_traverse(root);
    return 0;
}