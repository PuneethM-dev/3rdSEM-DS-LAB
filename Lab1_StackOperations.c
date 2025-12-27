#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

/* PUSH operation */
void push(int data)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow: Cannot push %d\n", data);
        return;
    }
    stack[++top] = data;
    printf("Pushed %d into the stack\n", data);
}

/* POP operation */
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow: Cannot pop\n");
        return;
    }
    printf("Popped %d from the stack\n", stack[top--]);
}

/* DISPLAY operation */
void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements:\n");
    for (int i = top; i >= 0; i--)
        printf("%d\n", stack[i]);
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}

