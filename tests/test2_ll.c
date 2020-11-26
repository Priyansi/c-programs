/*
WAP to create of  linked list of size of multiple of 4
In the set of 4
If there are 3 even and 1 odd / 3 odd and 1 even pair delete the odd or even element respectuvely
If there are 2 even and 2 odd elements, add the second odd element to the first odd element then delete the second odd element
If there are 4 evens or 4 odds, leave em
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int number_of_odds(int a, int b, int c, int d) {
    int arr[4] = {a, b, c, d};
    int num_odds = 0;
    for (int i = 0; i < 4; ++i) {
        if (arr[i] & 1) {
            ++num_odds;
        }
    }
    return num_odds;
}

void create(struct node** head, int len) {
    struct node* curr;
    struct node* ptr;
    int i;

    // accepting values
    for (i = 0; i < len * 4; ++i) {
        curr = (struct node*)malloc(sizeof(struct node));
        curr->data = random() % 50;
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
        printf("%d ", curr->data);
    }
    printf("\n");
}

void change(struct node** head) {
    if (*head == NULL) {
        return;
    }
    struct node* ptr;
    struct node* prv;
    int i, j;
    int num_odds;
    for (ptr = *head; ptr != NULL;) {
        num_odds = number_of_odds(ptr->data, ptr->next->data, ptr->next->next->data, ptr->next->next->next->data);
        if (num_odds & 1) {
            if (num_odds == 1) {
                for (ptr, i = 0; (ptr->data % 2 == 0) && (ptr != NULL) && (i < 4); prv = ptr, ptr = ptr->next, ++i)
                    ;
            } else {
                for (ptr, i = 0; (ptr->data & 1) && (ptr != NULL) && (i < 4); prv = ptr, ptr = ptr->next, ++i)
                    ;
            }
            if (ptr == *head) {
                *head = (*head)->next;
                free(ptr);
                ptr = (*head)->next->next->next;
            } else {
                prv->next = ptr->next;
                free(ptr);
                while (i < 4) {
                    prv = prv->next;
                    ++i;
                }
                ptr = prv;
            }
        } else if (num_odds == 2) {
            struct node* curr;
            for (ptr, i = 0; (ptr != NULL) && (i < 4); ptr = ptr->next, ++i) {
                if (ptr->data & 1) {
                    prv = ptr;
                    for (curr = ptr->next, j = ++i; (curr->data % 2 == 0) && (curr != NULL) && (j < 4); prv = curr, curr = curr->next, ++j)
                        ;
                    ptr->data += curr->data;
                    break;
                }
            }
            prv->next = curr->next;
            free(curr);
            while (j < 4) {
                prv = prv->next;
                ++j;
            }
            ptr = prv;
        } else {
            ptr = ptr->next->next->next->next;
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