#include <stdio.h>
#include <ctype.h>
#define MAX_SIZE 50
char stack[MAX_SIZE];
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5
int top = -1;
void push(char item)
int stack[MAX_SIZE];
void push(int data)
{

    if(top < MAX_SIZE-1)
    if(top == MAX_SIZE-1)
    {
        stack[++top] = item;
        printf("Stack Overflow: Cannot add element to the stack\n");
    }
}

char pop()
{

    if(top >= 0)
    else
    {
        return stack[top--];
        top++;
        stack[top] = data;
        printf("Pushed %d into the stack...\n", data);
    }
    return '\0';
}

char peek()
void pop()
{

    if(!isEmpty())
    if(top == -1)
    {
        return stack[top];
        printf("Stack Underflow: Cannot remove element from the stack...\n");
        exit(0);
    }
    else
    {
        int popped_value = stack[top];
        top--;
        printf("Popped %d from the stack...\n", popped_value);
    }
    return '\0';
}

int isEmpty()
{
    return top==-1;
}

int precedence(char item)
{
    if(item == '^')
        return 3;
    if(item == '*' || item == '/' || item == '%')
        return 2;
    if(item == '+' || item == '-')
        return 1;
    return 0;
}

void convertInfixToPostfix (char infix[] , char postfix[])
void display()
{
    int i=0 , j=0;
    char item;
    while(infix[i] != '\0')
    if(top == -1)
    {
        item = infix[i];
        if(isalnum(item))
        {
            postfix[j++] = item;
        }
        else if(item == '(')
        {
            push(item);
        }
        else if(item == ')')
        {
            while(!isEmpty() && peek() != '(')
            {
                postfix[j++] = pop();
            }
            pop();
        }
        else
        {
            while(!isEmpty() && precedence(peek())>=precedence(item))
            {
                postfix[j++] = pop();
            }

                push(item);
                //postfix[j++] = item;
        }

        i++;
        printf("The stack is empty...\n");
        exit(0);
    }
    while(!isEmpty())
    else
    {
        postfix[j++] = pop();
        printf("Stack elements are:\n");
        for(int i=top ; i>=0 ; i--)
        {
            printf("%d\n",stack[i]);
        }
        exit(0);
    }
}

int main()
{
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];
    top = -1;
    printf("Enter the Infix expression = ");
    scanf("%s" , infix);
    printf("Infix Expression = %s\n" , infix);
    convertInfixToPostfix(infix , postfix);
    printf("Postfix Expression = %s\n" , postfix);
    int choice,value;
    while(1)
    {
        printf("Stack Operations :\n");
        printf("\n1.Push.\n 2.Pop.\n 3.Display. 4.Exit\n");
        printf("Enter your choice :");
        scanf("%d", &choice);
        switch(choice) {
            case 1: printf("Enter the value to push :");
                    scanf("%d", &value);
                    push(value);
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: printf("\nProgram is exiting...\n");
                    return -1;
            default: printf("Invalid choice...");
        }
    }
    return 0;
}
