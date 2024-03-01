#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *link; //self referencing structure
}n;
    n *top=NULL;//global 
void llt(n *ptr)
{
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
}
int isempty(n* top)
{
    if(top==NULL)
    {
        printf("Stack is empty.");
        return 1;
    }
    return 0;

}
int isfull(n* top)
{
    n* s=(n*)malloc(sizeof(n));
    if(s==NULL)
    {
        printf("Stack is full.");
        return 1;
    }
    return 0;

}
n* push(n* top, int data)
{
    if(isfull(top))
    {
        printf("Stack overflow.");
    }
    n* temp=(n*)malloc(sizeof(n));
    temp->data=data;
    temp->link=top;
    top=temp;

    return top;
}
int pop(n* tp)
{
    if(isempty(tp))
    {
        printf("Stack underflow.");
    }
    n* temp=tp;
    top=tp->link;
    int x = temp->data;
    free(temp);
    return x;
}
int peek(int p)//p-position
{
    n* ptr=top;
    for(int i=0;(i<p-1 && ptr!=NULL);i++)
    {
        ptr=ptr->link;
    }
    if(ptr!=NULL)
    {
        return ptr->data;
    }
    return -1;
}
int stacktop(n* ptr)
{
    return ptr->data;
}
int stackbottom(n* ptr)
{    
    if(ptr!=NULL)
    {
        ptr=ptr->link;
    }
    return ptr->link->data;
}

int main()
{
    top=push(top, 12);
    top=push(top, 13);
    top=push(top, 14);
    top=push(top, 16);
    isempty(top);
    llt(top);
    int ele = pop(top);
    printf("\nPopped element is %d\n",ele);
    llt(top);
    printf("\nValue at position 1 is %d",peek(1));
    printf("\nTop value is: %d",stacktop(top));
    printf("\nBottom value is: %d",stackbottom(top));

return 0;

}