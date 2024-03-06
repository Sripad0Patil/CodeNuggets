#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

char push(st *ptr, char value)
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
int stacktop(st *sa)
{
    if (isEMPTY(sa))
    {
        return -1;
    }
    return sa->arr[sa->top];
}
int isOpertaor(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }
    return 0;
}
int presidency(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    else if (ch == '-' || ch == '+')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

char *InToPost(char *Infix)
{
    st *in = (st *)malloc(sizeof(st));
    in->size = 100;
    in->top = -1;
    in->arr = (char *)malloc(in->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(Infix) + 1) * sizeof(char));
    int i = 0, j = 0;
    while (Infix[i] != '\0')
    {
        if (!isOpertaor(Infix[i]))
        {
            postfix[j] = Infix[i];
            j++;
            i++;
        }
        else
        {
            if (presidency(Infix[i]) > presidency(stacktop(in)))
            {
                postfix[j] = push(in, Infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(in);
                j++;
            }
        }
    }
    while ((!isEMPTY(in)))
    {
        postfix[j] = pop(in);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{

    char exp[20];
    printf("Enter an expression: ");
    scanf("%s", exp);
    printf("Infix exp: %s\n", exp);
    printf("Infix to postfix: %s\n", InToPost(exp));

    return 0;
}