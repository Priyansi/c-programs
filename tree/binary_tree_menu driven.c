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

void preorder_traverse_recr(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder_traverse_recr(root->left);
        preorder_traverse_recr(root->right);
    }
}

void inorder_traverse_recr(struct node* root) {
    if (root != NULL) {
        inorder_traverse_recr(root->left);
        printf("%d ", root->data);
        inorder_traverse_recr(root->right);
    }
}

void postorder_traverse_recr(struct node* root) {
    if (root != NULL) {
        postorder_traverse_recr(root->left);
        postorder_traverse_recr(root->right);
        printf("%d ", root->data);
    }
}

void preorder_traverse_iter(struct node* root) {
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

void inorder_traverse_iter(struct node* root) {
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

void postorder_traverse_iter(struct node* root) {
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

int search_iter(struct node* root, int val) {
    struct node* curr = root;
    while (curr != NULL) {
        if (curr->data == val) {
            printf("Node %d is present in the BST\n", val);
            return 1;
        } else if (curr->data > val) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    printf("Node %d not found in the BST\n", val);
    return 0;
}

int search_recr(struct node* root, int val) {
    if (root == NULL) {
        printf("Node %d not found in the BST\n", val);
        return 0;
    } else {
        if (root->data == val) {
            printf("Node %d is present in the BST\n", val);
            return 1;
        } else if (root->data > val) {
            return search_iter(root->left, val);
        } else {
            return search_iter(root->right, val);
        }
    }
}

void max_tree_recr(struct node* root) {
    if (root->right == NULL) {
        printf("%d is the maxiumum node in the heap\n", root->data);
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
        printf("%d is the maxiumum node in the heap\n", curr->data);
    }
}

void min_tree_recr(struct node* root) {
    if (root->left == NULL) {
        printf("%d is the maxiumum node in the heap\n", root->data);
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
        printf("%d is the maxiumum node in the heap\n", curr->data);
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
    int choice, val;
    while (1) {
        printf("Enter 0 to exit-\n");
        printf("A BST has been created. Here is what you can do with it. Enter the bullet point as an option -\n");
        printf("Traversal-\n1. Inorder Iterative\n2. Inorder Recursive\n3. Preorder Iterative\n4. Preorder Recursive\n5. Postorder Iterative\n6. Postorder Recursive\n");
        printf("Search-\n7. Iterative\n8. Recursive\n");
        printf("Maximum in the BST-\n9. Iterative\n10. Recursive\n");
        printf("Minimum in the BST-\n11. Iterative\n12. Recursive\n");
        scanf("%d", &choice);
        if (choice == 0) {
            break;
        }
        switch (choice) {
            case 1:
                inorder_traverse_iter(root);
                break;
            case 2:
                inorder_traverse_recr(root);
                break;
            case 3:
                preorder_traverse_iter(root);
                break;
            case 4:
                preorder_traverse_recr(root);
                break;
            case 5:
                postorder_traverse_iter(root);
                break;
            case 6:
                postorder_traverse_recr(root);
                break;
            case 7:
                printf("Enter value to be searched - ");
                scanf("%d", &val);
                search_iter(root, val);
                break;
            case 8:
                printf("Enter value to be searched - ");
                scanf("%d", &val);
                search_recr(root, val);
                break;
            case 9:
                max_tree_iter(root);
                break;
            case 10:
                max_tree_recr(root);
                break;
            case 11:
                min_tree_iter(root);
                break;
            case 12:
                min_tree_recr(root);
                break;
            default:
                printf("Enter the right choice.\n");
        }
    }
    return 0;
}