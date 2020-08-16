#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int main(int argc, char* argv[]) {
    int len = atoi(argv[1]);
    struct node* head = NULL;
    struct node* tail = NULL;
    struct node* curr;
    int i;

    // accepting values
    for (i = 0; i < len; ++i) {
        curr = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &curr->data);
        curr->next = NULL;
        if (head == NULL) {
            head = curr;
            tail = curr;
        } else {
            tail->next = curr;
            tail = tail->next;
        }
    }

    // printing values
    curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    return 0;
}