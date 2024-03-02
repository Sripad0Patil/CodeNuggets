#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int size;
    int top;
    char *arr;
} st;

int isFULL(st *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        printf("\nStack is full.");
        return 1;
    }
    return 0;
}

int isEMPTY(st *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

void push(st *ptr, char value)
{
    if (isFULL(ptr))
    {
        printf("\nStack overflow!! connot push %c in stack", value);
    }
    ptr->top++;
    ptr->arr[ptr->top] = value;
}

char pop(st *ptr)
{
    if (isEMPTY(ptr))
    {
        printf("\nStack undflow");
    }
    char val = ptr->arr[ptr->top];
    ptr->top--;
    return val;
}

int match(char *exp)
{
    st *ss = (st *)malloc(sizeof(st));
    ss->size = 20;
    ss->top = -1;
    ss->arr = (char *)malloc(ss->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(ss, '(');
        }
        else if (exp[i] == ')')
        {
            while (pop(ss) != '(')
            {
                if (isEMPTY(ss))
                {
                    return 0;
                }
                //pop(ss);
            }
        }
    }

    if (isEMPTY(ss))
    {
        return 1;
    }
    return 0;
}

int main()
{

    char exp[20];
    printf("Enter an expression: ");
    scanf("%s",exp);
    printf("Given exp: %s",exp);
    if (match(exp))
    {
        printf("\nMatch found ");
    }
    else
    {
        printf("\nMatch not found");
    }

    return 0;
}