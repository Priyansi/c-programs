#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int list_len(struct node* head) {
    struct node* curr;
    int len = 0;
    for (curr = head; curr != NULL; curr = curr->next) {
        ++len;
    }
    return len;
}

void delete_list(struct node** head) {
    struct node* curr;
    while (*head != NULL) {
        curr = *head;
        *head = (*head)->next;
        free(curr);
    }
}

void reverse(struct node** head) {
    struct node* ptr1 = *head;
    struct node* ptr2;
    while (ptr1->next != NULL) {
        ptr2 = ptr1->next;
        ptr1->next = ptr2->next;
        ptr2->next = *head;
        *head = ptr2;
    }
}

void reverse_alter(struct node** head) {
    struct node* curr = *head;
    struct node* nxt;
    struct node* prv = NULL;
    int len = list_len(*head);
    while (curr != NULL && len > 0) {
        nxt = curr->next;
        curr->next = prv;
        prv = curr;
        curr = nxt;
    }
}

void create(struct node** head, int len) {
    struct node* curr;
    struct node* ptr;
    int i;

    // accepting values
    for (i = 0; i < len; ++i) {
        curr = (struct node*)malloc(sizeof(struct node));
        curr->data = random() % 20;
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

void display_rev(struct node* head) {
    struct node* curr;
    struct node* last;
    int len = list_len(head);
    while (len--) {
        for (curr = head; curr->next != last; curr = curr->next)
            ;
        printf("%d ", curr->data);
        last = curr;
    }
    printf("\n");
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
    curr->next = NULL;
    if (*head == NULL) {
        *head = curr;
    } else if (pos == 0) {
        curr->next = *head;
        *head = curr;
    } else {
        ptr = *head;
        int i = 0;
        while (i < pos && ptr->next != NULL) {
            ptr = ptr->next;
            ++i;
        }
        curr->next = ptr->next;
        ptr->next = curr;
    }
}

void delete (struct node** head, int pos) {
    struct node* ptr;
    struct node* prev;
    if (*head == NULL) {
        printf("Empty");
    } else {
        ptr = *head;
        int i = 0;
        while (i < pos && ptr->next != NULL) {
            prev = ptr;
            ptr = ptr->next;
            ++i;
        }
        if (ptr == NULL) {
            printf("Node not found");
        } else if (ptr == *head) {
            *head = ptr->next;
            free(ptr);
        } else {
            prev->next = ptr->next;
            free(ptr);
        }
    }
}

int main(int argc, char* argv[]) {
    int len = atoi(argv[1]);
    struct node* head = NULL;
    create(&head, len);
    display(head);
    reverse(&head);
    display(head);
    //delete_list(&head);
    // printing value
    return 0;
}