#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push(int element)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = element;
    printf("%d pushed to stack\n", element);
}

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
       
    }
    printf("Elements in stack are: ");
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int isPalindrome(char *str)
{
    int i, len;
    for (len = 0; str[len] != '\0'; len++)
        ;
    for (i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - i - 1])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int choice, element;
    char str[MAX];

    while (1)
    {
        printf("\n1. Push Element\n");
        printf("2. Pop Element\n");
        printf("3. Check Palindrome\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to push: ");
            scanf("%d", &element);
            push(element);
            break;
        case 2:
            element = pop();
            if (element != -1)
            {
                printf("Popped element: %d\n", element);
            }
            break;
        case 3:
            printf("Enter a string: ");
            scanf("%s", str);
            if (isPalindrome(str))
            {
                printf("The string is a palindrome.\n");
            }
            else
            {
                printf("The string is not a palindrome.\n");
            }
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
