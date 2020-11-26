#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* prev;
    struct node* next;
};

void reverse(struct node** head) {
    struct node* prv;
    struct node* ptr;
    if (*head == NULL) {
        return;
    }
    for (prv = *head, ptr = prv->next;; prv = ptr, ptr = prv->next) {
        prv->next = prv->prev;
        prv->prev = ptr;
        if (ptr == NULL) {
            break;
        }
    }
    *head = prv;
}

void create(struct node** head, int len) {
    struct node* curr;
    struct node* ptr;
    int i;

    // accepting values
    for (i = 0; i < len; ++i) {
        curr = (struct node*)malloc(sizeof(struct node));
        curr->data = random() % 20;
        curr->prev = curr->next = NULL;
        if (*head == NULL) {
            *head = curr;
            ptr = curr;
        } else {
            curr->prev = ptr;
            ptr->next = curr;
            ptr = curr;
        }
    }
}

void display(struct node* head) {
    struct node* curr;
    for (curr = head; curr != NULL; curr = curr->next) {
        printf("%d ", curr->data);
    }
    printf("\n");
}

void insert(struct node** head, int val, int pos) {
    struct node* curr;
    struct node* ptr;
    curr = (struct node*)malloc(sizeof(struct node));
    curr->data = val;
    curr->prev = curr->next = NULL;
    if (*head == NULL) {
        *head = curr;
    } else if (pos == 0) {
        curr->next = *head;
        (*head)->prev = curr;
        *head = curr;
    } else {
        ptr = *head;
        int i = 0;
        while (i < pos && ptr->next != NULL) {
            ptr = ptr->next;
            ++i;
        }
        if (ptr->next == NULL) {
            curr->prev = ptr;
            ptr->next = curr;
        } else {
            curr->prev = ptr;
            curr->next = ptr->next;
            ptr->next = curr;
            curr->next->prev = ptr;
        }
    }
}

void delete (struct node** head, int pos) {
    struct node* ptr = *head;
    if (*head == NULL) {
        printf("Empty");
    } else if (pos == 0) {
        if (ptr->next != NULL) {
            *head = ptr->next;
            (*head)->prev = NULL;
            free(ptr);
        } else {
            *head = ptr->next;
            (*head)->prev = NULL;
            free(ptr);
        }
    } else {
        int i = 0;
        while (i < pos && ptr->next != NULL) {
            ptr = ptr->next;
            ++i;
        }
        if (i < pos) {
            printf("Node not found\n");
        } else if (ptr->next == NULL) {
            ptr->prev->next = NULL;
            free(ptr);
        } else {
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            free(ptr);
        }
    }
}

int main(int argc, char* argv[]) {
    int len = atoi(argv[1]);
    struct node* head = NULL;

    create(&head, 5);
    display(head);
    delete (&head, 8);
    display(head);

    return 0;
}