#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    int exp;
    struct node* next;
};

void create(struct node** head, int len) {
    struct node* curr;
    struct node* ptr;
    int i;

    // accepting values
    for (i = 0; i < len; ++i) {
        curr = (struct node*)malloc(sizeof(struct node));
        curr->data = random() % 20;
        curr->exp = random() % len;
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

void display(struct node* head) {
    struct node* curr;
    for (curr = head; curr != NULL; curr = curr->next) {
        printf("%d %d\t", curr->data, curr->exp);
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

void simplify(struct node* head) {
    struct node* ptr_i;
    struct node* ptr_j;
    struct node* prev;
    for (ptr_i = head; ptr_i != NULL; ptr_i = ptr_i->next) {
        prev = ptr_i;
        for (ptr_j = ptr_i->next; ptr_j != NULL; prev = ptr_j, ptr_j = ptr_j->next) {
            if (ptr_j->exp == ptr_i->exp) {
                ptr_i->data += ptr_j->data;
                prev->next = ptr_j->next;
                free(ptr_j);
                ptr_j = prev;
            }
        }
    }
}

void add(struct node** head1, struct node* head2) {
    join(head1, head2);
    simplify(*head1);
}

void subtract(struct node** head1, struct node* head2) {
    struct node* ptr;
    for (ptr = head2; ptr != NULL; ptr = ptr->next) {
        ptr->data *= -1;
    }
    join(head1, head2);
    simplify(*head1);
}

void multiply(struct node** head1, struct node* head2) {
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
            curr->exp = ptr_i->exp + ptr_j->exp;
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
    simplify(*head1);
}

int main(int argc, char* argv[]) {
    int len1 = atoi(argv[1]);
    int len2 = atoi(argv[2]);
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    create(&head1, len1);
    create(&head2, len2);
    display(head1);
    display(head2);
    multiply(&head1, head2);
    display(head1);
    return 0;
}