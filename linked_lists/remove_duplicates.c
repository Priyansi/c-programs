#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void create(struct node** head, int len) {
    struct node* curr;
    struct node* ptr;
    int i;

    // accepting values
    for (i = 0; i < len; ++i) {
        curr = (struct node*)malloc(sizeof(struct node));
        curr->data = random() % 10;
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
        printf("%d->", curr->data);
    }
    printf("NULL\n");
}

void remove_duplicates(struct node* head) {
    struct node* ptr_i;
    struct node* ptr_j;
    struct node* prev;
    for (ptr_i = head; ptr_i != NULL; ptr_i = ptr_i->next) {
        prev = ptr_i;
        for (ptr_j = ptr_i->next; ptr_j != NULL; prev = ptr_j, ptr_j = ptr_j->next) {
            if (ptr_j->data == ptr_i->data) {
                prev->next = ptr_j->next;
                free(ptr_j);
                ptr_j = prev;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    int len = atoi(argv[1]);
    struct node* head = NULL;
    create(&head, len);
    display(head);
    remove_duplicates(head);
    display(head);
    return 0;
}