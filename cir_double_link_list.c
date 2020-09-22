#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* prev;
    struct node* next;
};

int list_len(struct node* head) {
    struct node* curr;
    int len = 0;
    if (head == NULL) {
        return len;
    }
    curr = head;
    do {
        curr = curr->next;
        ++len;
    } while (curr->next != head);
    return ++len;
}

void create(struct node** head, int len) {
    struct node* curr;
    struct node* ptr;
    int i;

    // accepting values
    for (i = 0; i < len; ++i) {
        curr = (struct node*)malloc(sizeof(struct node));
        curr->data = random() % 20;
        curr->next = curr->prev = NULL;
        if (*head == NULL) {
            *head = curr;
            ptr = curr;
            (*head)->next = (*head)->prev = curr;
        } else {
            curr->next = *head;
            curr->prev = ptr;
            ptr->next = curr;
            (*head)->prev = curr;
            ptr = curr;
        }
    }
}

void display(struct node* head) {
    struct node* curr;
    if (head == NULL) {
        return;
    }
    for (curr = head; curr->next != head; curr = curr->next) {
        printf("%d ", curr->data);
    }
    printf("%d", curr->data);  // last node
    printf("\n");
}

void insert(struct node** head, int val, int pos) {
    struct node* curr;
    struct node* ptr;
    curr = (struct node*)malloc(sizeof(struct node));
    curr->data = val;
    curr->next = NULL;
    if (*head == NULL) {
        *head = curr;
        curr->next = curr->prev = curr;
    } else if (pos == 0) {
        curr->next = (*head);
        curr->prev = (*head)->prev;
        (*head)->prev->next = curr;
        (*head)->prev = curr;
        *head = curr;
    } else {
        ptr = *head;
        pos = pos % list_len(*head);
        int i = 0;
        while (i < pos) {
            ptr = ptr->next;
            ++i;
        }
        curr->next = ptr->next;
        curr->prev = ptr;
        ptr->next->prev = curr;
        ptr->next = curr;
    }
}

void search(struct node* head, int val) {
    struct node* ptr;
    if (head == NULL) {
        printf("Empty");
    } else {
        ptr = head;
        while (ptr->next != head) {
            if (ptr->data == val) {
                printf("Value found.\n");
                return;
            }
            ptr = ptr->next;
        }
    }
    printf("Value not found.\n");
}

void delete (struct node** head, int pos) {
    struct node* ptr = *head;
    if (*head == NULL) {
        printf("Empty");
    } else if (*head == (*head)->next) {
        *head = NULL;
        free(ptr);
    } else {
        pos = pos % list_len(*head);
        int i = 0;
        while (i < pos && ptr->next != *head) {
            ptr = ptr->next;
            ++i;
        }
        if (pos == 0) {
            (*head)->prev->next = (*head)->next;
            (*head)->next->prev = (*head)->prev;
            (*head) = (*head)->next;
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
    create(&head, len);
    display(head);
    insert(&head, 30, 0);
    display(head);
    delete (&head, 7);
    display(head);
    return 0;
}