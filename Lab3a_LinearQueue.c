#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5
int queue[MAX_SIZE];
int front = -1;
int rear = -1;
int isFull()
{
    return rear == MAX_SIZE - 1;
}
int isEmpty()
{
    return front == -1;
}
void insert(int value)
{
    if(isFull())
    {
        printf("\nQueue Overflow...\n");
        return;
    }
    if(front == -1)
    {
        front = 0;
    }
    queue[++rear] = value;
    printf("\nInserted %d into queue...\n" , value);
}
void delete()
{
    if(isEmpty())
    {
        printf("\nQueue Underflow...\n");
        return;
    }
    printf("\nDeleted %d from the queue...\n" , queue[front]);
    if(front  == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
}
void display()
{
    if(isEmpty())
    {
        printf("\nQueue Underflow...\n");
        return;
    }
    printf("\nQueue elements are : \n");
    for(int i=front ; i<=rear ; i++)
    {
        printf(" %d " , queue[i]);
    }
    printf("\n");
}
int main()
{
    int choice,value;
    while(1)
    {
        printf("\nQueue Operations : \n");
        printf("\n 1.Enqueue\n 2.Dequeue\n 3.Display\n 4.Exit\n");
        printf("Enter your choice = ");
        scanf("%d" , &choice);
        switch(choice)
        {
            case 1: printf("Enter the element to insert = ");
                    scanf("%d" , &value);
                    insert(value);
                    break;
            case 2: delete();
                    break;
            case 3: display();
                    break;
            case 4: printf("\n Program is exiting...\n");
                    exit(0);
            default: printf("\n Invalid Operation...\n");
        }
    }
    return 0;
}
