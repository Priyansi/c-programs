#include <stdio.h>
#include <stdlib.h>

struct node {
    int row, col, val;
    struct node* next;
};

void create(struct node** head, int row, int col, int val) {
    struct node* curr;
    struct node* ptr;
    int i;
    *head = (struct node*)malloc(sizeof(struct node));
    (*head)->row = row;
    (*head)->col = col;
    (*head)->val = val;
    (*head)->next = NULL;
    ptr = *head;
    // accepting values
    for (i = 0; i < (*head)->val; ++i) {
        curr = (struct node*)malloc(sizeof(struct node));
        curr->row = random() % row;
        curr->col = random() % col;
        curr->val = random() % 20;
        curr->next = NULL;
        ptr->next = curr;
        ptr = curr;
    }
}

void display_ll(struct node* head) {
    struct node* curr;
    for (curr = head; curr != NULL; curr = curr->next) {
        printf("%d %d %d\n", curr->row, curr->col, curr->val);
    }
    printf("\n");
}

void display_matrix(struct node* head) {
    struct node* curr;
    int row, col;
    int flag;
    for (row = 0; row < head->row; ++row) {
        for (col = 0; col < head->col; ++col) {
            flag = 0;
            for (curr = head->next; curr != NULL; curr = curr->next) {
                if (row == curr->row && col == curr->col) {
                    flag = 1;
                    break;
                }
            }
            printf("%d ", (flag) ? curr->val : 0);
        }
        printf("\n");
    }
    printf("\n");
}

void transpose(struct node* head) {
    struct node* curr;
    int temp;
    for (curr = head; curr != NULL; curr = curr->next) {
        temp = curr->row;
        curr->row = curr->col;
        curr->col = temp;
    }
}

void join(struct node** head1, struct node* head2, struct node** head3) {
    struct node* ptr;
    struct node* ptr_i;
    struct node* curr;
    if ((*head1)->row != head2->row || (*head1)->col != head2->col) {
        return;
    }
    *head3 = (struct node*)malloc(sizeof(struct node));
    (*head3)->row = (*head1)->row;
    (*head3)->col = (*head1)->col;
    (*head3)->val = 0;
    (*head3)->next = NULL;
    ptr = *head3;
    for (ptr_i = *head1; ptr_i != NULL; ptr_i = ptr_i->next) {
        curr = (struct node*)malloc(sizeof(struct node));
        curr->row = ptr_i->row;
        curr->col = ptr_i->col;
        curr->val = ptr_i->val;
        curr->next = NULL;
        ptr->next = curr;
        ptr = curr;
        (*head3)->val++;
    }
    for (ptr_i = head2; ptr_i != NULL; ptr_i = ptr_i->next) {
        curr = (struct node*)malloc(sizeof(struct node));
        curr->row = ptr_i->row;
        curr->col = ptr_i->col;
        curr->val = ptr_i->val;
        curr->next = NULL;
        ptr->next = curr;
        ptr = curr;
        (*head3)->val++;
    }
}

void simplify(struct node* head3) {
    struct node* ptr_i;
    struct node* ptr_j;
    struct node* prev;
    for (ptr_i = head3->next; ptr_i != NULL; ptr_i = ptr_i->next) {
        prev = ptr_i;
        for (ptr_j = ptr_i->next; ptr_j != NULL; prev = ptr_j, ptr_j = ptr_j->next) {
            if (ptr_i->row == ptr_j->row && ptr_i->col == ptr_j->col) {
                ptr_i->val += ptr_j->val;
                prev->next = ptr_j->next;
                free(ptr_j);
                ptr_j = prev;
                head3->val--;
            }
        }
    }
}

void add(struct node** head1, struct node* head2, struct node** head3) {
    join(head1, head2, head3);
    simplify(*head3);
}

void multiply(struct node* head1, struct node* head2, struct node** head3) {
    if (head1->col != head2->row) {
        return;
    }
    struct node* ptr_i;
    struct node* ptr_j;
    struct node* curr;
    struct node* ptr;
    *head3 = (struct node*)malloc(sizeof(struct node));
    (*head3)->row = (head1)->row;
    (*head3)->col = (head2)->col;
    (*head3)->val = 0;
    (*head3)->next = NULL;
    ptr = (*head3);
    for (ptr_i = head1->next; ptr_i != NULL; ptr_i = ptr_i->next) {
        for (ptr_j = head2->next; ptr_j != NULL; ptr_j = ptr_j->next) {
            if (ptr_i->col == ptr_j->row) {
                curr = (struct node*)malloc(sizeof(struct node));
                curr->row = ptr_i->row;
                curr->col = ptr_j->col;
                curr->val = ptr_i->val * ptr_j->val;
                curr->next = NULL;
                ptr->next = curr;
                ptr = curr;
                (*head3)->val++;
            }
        }
    }
    simplify(*head3);
}

int main(int argc, char* argv[]) {
    int row1 = atoi(argv[1]);
    int col1 = atoi(argv[2]);
    int row2 = atoi(argv[3]);
    int col2 = atoi(argv[4]);
    int val1 = atoi(argv[5]);
    int val2 = atoi(argv[6]);
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    struct node* head3 = NULL;
    create(&head1, row1, col1, val1);
    create(&head2, row2, col2, val2);
    display_matrix(head1);
    display_matrix(head2);
    multiply(head1, head2, &head3);
    display_matrix(head3);
    return 0;
}