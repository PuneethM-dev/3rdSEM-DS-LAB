#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};


struct node *top = NULL;


struct node *front = NULL;
struct node *rear = NULL;


void push(int x) {
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

void pop() {
    struct node *temp;
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    temp = top;
    top = top->next;
    free(temp);
}

void displayStack() {
    struct node *temp = top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void enqueue(int x) {
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;

    if (front == NULL) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    struct node *temp;
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    temp = front;
    front = front->next;
    free(temp);

    if (front == NULL)
        rear = NULL;
}

void displayQueue() {
    struct node *temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {

    printf("Stack operations:\n");
    push(10);
    push(20);
    push(30);
    displayStack();

    pop();
    printf("After pop:\n");
    displayStack();


    printf("\nQueue operations:\n");
    enqueue(100);
    enqueue(200);
    enqueue(300);
    displayQueue();

    dequeue();
    printf("After dequeue:\n");
    displayQueue();

    return 0;
}
