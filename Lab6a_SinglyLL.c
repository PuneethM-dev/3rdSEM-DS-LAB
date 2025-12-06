#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head1 = NULL;
struct node *head2 = NULL;

void insertEnd(struct node **head, int value) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    }
    else {
        struct node *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void display(struct node *head) {
    struct node *temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void sortList(struct node *head) {
    struct node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void reverseList(struct node **head) {
    struct node *prev = NULL, *cur = *head, *next;

    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    *head = prev;
}

struct node* concatenate(struct node *h1, struct node *h2) {
    if (h1 == NULL) return h2;
    if (h2 == NULL) return h1;

    struct node *temp = h1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = h2;
    return h1;
}

int main() {

    // creating first list
    insertEnd(&head1, 30);
    insertEnd(&head1, 10);
    insertEnd(&head1, 20);

    // creating second list
    insertEnd(&head2, 40);
    insertEnd(&head2, 60);
    insertEnd(&head2, 50);

    printf("First Linked List:\n");
    display(head1);

    printf("Second Linked List:\n");
    display(head2);

    // sort first list
    sortList(head1);
    printf("After sorting first list:\n");
    display(head1);

    // reverse first list
    reverseList(&head1);
    printf("After reversing first list:\n");
    display(head1);

    // concatenate lists
    struct node *final = concatenate(head1, head2);
    printf("After concatenation of lists:\n");
    display(final);

    return 0;
}
