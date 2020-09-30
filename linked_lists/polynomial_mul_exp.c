#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    int* exp;
    struct node* next;
};

void create(struct node** head, int len, int num_exp) {
    struct node* curr;
    struct node* ptr;
    int i;

    // accepting values
    for (i = 0; i < len; ++i) {
        curr = (struct node*)malloc(sizeof(struct node));
        curr->data = random() % 20;
        curr->exp = (int*)malloc(sizeof(int));
        for (int i = 0; i < num_exp; ++i) {
            curr->exp[i] = random() % 3;
        }
        curr->next = NULL;
        if (*head == NULL) {
            *head = curr;
            ptr = curr;
        } else {
            ptr->next = curr;
            ptr = curr;
        }
    }
}

void display(struct node* head, int num_exp) {
    struct node* curr;
    for (curr = head; curr != NULL; curr = curr->next) {
        printf("%d - ", curr->data);
        for (int i = 0; i < num_exp; ++i) {
            printf("%d ", curr->exp[i]);
        }
        printf("\t");
    }
    printf("\n");
}

void join(struct node** head1, struct node* head2) {
    if (*head1 == NULL || head2 == NULL) {
        return;
    }
    if ((*head1)->next == NULL) {
        (*head1)->next = head2;
    } else {
        join(&((*head1)->next), head2);
    }
}

void simplify(struct node* head, int num_exp) {
    struct node* ptr_i;
    struct node* ptr_j;
    struct node* prev;
    int is_exp_same;
    for (ptr_i = head; ptr_i != NULL; ptr_i = ptr_i->next) {
        prev = ptr_i;
        for (ptr_j = ptr_i->next; ptr_j != NULL; prev = ptr_j, ptr_j = ptr_j->next) {
            is_exp_same = 1;
            for (int i = 0; i < num_exp; ++i) {
                if (ptr_j->exp[i] != ptr_i->exp[i]) {
                    is_exp_same = 0;
                    break;
                }
            }
            if (is_exp_same) {
                ptr_i->data += ptr_j->data;
                prev->next = ptr_j->next;
                free(ptr_j);
                ptr_j = prev;
            }
        }
    }
}

void add(struct node** head1, struct node* head2, int num_exp) {
    join(head1, head2);
    simplify(*head1, num_exp);
}

void subtract(struct node** head1, struct node* head2, int num_exp) {
    struct node* ptr;
    for (ptr = head2; ptr != NULL; ptr = ptr->next) {
        ptr->data *= -1;
    }
    join(head1, head2);
    simplify(*head1, num_exp);
}

void multiply(struct node** head1, struct node* head2, int num_exp) {
    struct node* ptr_i;
    struct node* ptr_j;
    struct node* head3;
    struct node* ptr;
    head3 = ptr = NULL;
    struct node* curr;
    for (ptr_i = *head1; ptr_i != NULL; ptr_i = ptr_i->next) {
        for (ptr_j = head2; ptr_j != NULL; ptr_j = ptr_j->next) {
            curr = (struct node*)malloc(sizeof(struct node));
            curr->data = ptr_i->data * ptr_j->data;
            curr->exp = (int*)malloc(sizeof(int));
            for (int i = 0; i < num_exp; ++i) {
                curr->exp[i] = ptr_i->exp[i] + ptr_j->exp[i];
            }
            if (head3 == NULL) {
                head3 = curr;
                ptr = curr;
            } else {
                ptr->next = curr;
                ptr = curr;
            }
        }
    }
    *head1 = head3;
    simplify(*head1, num_exp);
}

int main(int argc, char* argv[]) {
    int len1 = atoi(argv[1]);
    int len2 = atoi(argv[2]);
    int num_exp = atoi(argv[3]);
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    create(&head1, len1, num_exp);
    create(&head2, len2, num_exp);
    display(head1, num_exp);
    display(head2, num_exp);
    multiply(&head1, head2, num_exp);
    display(head1, num_exp);
    return 0;
}