/*
WAP to create of  linked list of size of multiple of 3
Each node consists 3 elements data, index(0/1),pointer
In the set of 3
if the middle one is different from the next and previous index
then kill it
And if the outside index is different from the next 2 then put it in middle
And if all 3 index are same then leave them as it is
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    int ind;
    struct node* next;
};

void create(struct node** head, int len) {
    struct node* curr;
    struct node* ptr;
    int i;

    // accepting values
    for (i = 0; i < len * 3; ++i) {
        curr = (struct node*)malloc(sizeof(struct node));
        curr->data = random() % 50;
        curr->ind = random() % 2;
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
        printf("%d %d\t", curr->data, curr->ind);
    }
    printf("\n");
}

void change(struct node** head) {
    if (*head == NULL) {
        return;
    }
    struct node* beg;
    struct node* mid;
    struct node* end;
    for (beg = *head; beg != NULL; beg = end->next) {
        mid = beg->next;
        end = mid->next;
        if ((beg->ind == end->ind) && (beg->ind != mid->ind)) {
            struct node* temp;
            beg->next = end;
            temp = mid;
            mid = NULL;
            free(temp);
        } else if ((mid->ind == end->ind) && (beg->ind != mid->ind)) {
            if (*head == beg) {
                *head = mid;
            } else {
                struct node* temp;
                for (temp = *head; temp->next != beg; temp = temp->next)
                    ;
                temp->next = mid;
            }
            mid->next = beg;
            beg->next = end;
        } else if ((beg->ind == mid->ind) && (mid->ind != end->ind)) {
            mid->next = end->next;
            end->next = mid;
            beg->next = end;
            end = mid;
        }
    }
}

int main(int argc, char* argv[]) {
    int len = atoi(argv[1]);
    struct node* head = NULL;
    create(&head, len);
    display(head);
    change(&head);
    display(head);
    return 0;
}