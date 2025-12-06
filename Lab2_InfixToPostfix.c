#include <stdio.h>
#include <ctype.h>
#define MAX_SIZE 50
char stack[MAX_SIZE];
int top = -1;
void push(char item)
{

    if(top < MAX_SIZE-1)
    {
        stack[++top] = item;
    }
}

char pop()
{

    if(top >= 0)
    {
        return stack[top--];
    }
    return '\0';
}

char peek()
{

    if(!isEmpty())
    {
        return stack[top];
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
{
    int i=0 , j=0;
    char item;
    while(infix[i] != '\0')
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
    }
    while(!isEmpty())
    {
        postfix[j++] = pop();
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
    return 0;
}
