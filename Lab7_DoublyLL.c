#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *prev;
    struct node *next;
};

struct node *start = NULL;

void create(int x) {
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->info = x;
    newnode->prev = NULL;
    newnode->next = NULL;

    if (start == NULL) {
        start = newnode;
        return;
    }
    temp = start;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;
}

void insert_left(int key, int x) {
    struct node *newnode, *temp;
    temp = start;

    while (temp != NULL && temp->info != key)
        temp = temp->next;

    if (temp == NULL)
        return;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->info = x;
    newnode->next = temp;
    newnode->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = newnode;
    else
        start = newnode;

    temp->prev = newnode;
}

void delete_node(int key) {
    struct node *temp;
    temp = start;

    while (temp != NULL && temp->info != key)
        temp = temp->next;

    if (temp == NULL)
        return;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        start = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

void display() {
    struct node *temp;
    temp = start;

    while (temp != NULL) {
        printf("%d <-> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    create(10);
    create(20);
    create(30);

    insert_left(20, 15);
    delete_node(30);

    display();
    return 0;
}
