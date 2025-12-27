#include <stdio.h>
#include <ctype.h>

#define MAX 50

char stack[MAX];
int top = -1;

/* Stack operations */
void push(char x)
{
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = x;
}

char pop()
{
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

char peek()
{
    return stack[top];
}

int isEmpty()
{
    return top == -1;
}

/* Precedence function */
int precedence(char x)
{
    if (x == '^') return 3;
    if (x == '*' || x == '/' || x == '%') return 2;
    if (x == '+' || x == '-') return 1;
    return 0;
}

/* Infix to Postfix conversion */
void infixToPostfix(char infix[], char postfix[])
{
    int i = 0, j = 0;
    char item;

    while (infix[i] != '\0')
    {
        item = infix[i];

        if (isalnum(item))            // operand
        {
            postfix[j++] = item;
        }
        else if (item == '(')
        {
            push(item);
        }
        else if (item == ')')
        {
            while (!isEmpty() && peek() != '(')
                postfix[j++] = pop();
            pop(); // remove '('
        }
        else                          // operator
        {
            while (!isEmpty() && precedence(peek()) >= precedence(item))
                postfix[j++] = pop();
            push(item);
        }
        i++;
    }

    while (!isEmpty())
        postfix[j++] = pop();

    postfix[j] = '\0';
}

/* Main */
int main()
{
    char infix[MAX], postfix[MAX];

    printf("Enter Infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
