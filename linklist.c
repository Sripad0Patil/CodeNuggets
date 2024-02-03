#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *link; //self referencing structure
}n;
//traversing linkedlist
void llt(n *ptr)
{
    while(ptr!=NULL)
    {
        printf("Element: %d\n",ptr->data);
        ptr = ptr->link;
    }
}
//inserting new node at first
n* insert(n *head, int data)
{
    n *ptr=(n*)malloc(sizeof(n));
    ptr->link=head;
    ptr->data=data;
    return ptr;
}
//inserting new node at given index
n  *inesrtatindex(n *head, int data, int index)
{
    n *ptr=(n*)malloc(sizeof(n));
    n *p = head;
    int i=0;
    while(i!=index-1)
    {
        p = p->link;
        i++;
    }
    ptr->data=data;
    ptr->link=p->link;
    p->link=ptr;
    return head;

}
//inserting a node at end
n *in(n *head, int data)
{
    n *ptr=(n*)malloc(sizeof(n));
    n* p = head;
    
    while(p->link!=NULL)
    {
        p = p->link;
    }
    ptr->data=data;
    p->link=ptr;
    ptr->link=NULL;
    return head;
}
//deleting first node
n* deletefirst(n* head)
{
    n* ptr=head;
    head=head->link;
    free(ptr);
    return head;
}
//deleting node at given index
n* deleteAtIndex(n* head, int index)
{
    
    n* p = head;
    n* q = head->link;
    for(int i=0;i<index-1;i++)
    {
        p=p->link;
        q=q->link;
    }
    p->link=q->link;
    free(q);
    return head;
}
//delete last node
n* delast(n* head)
{
    n* p = head;
    n* q = head->link;
    while(q->link!=NULL)
    {
        p=p->link;
        q=q->link;
    }
    p->link=NULL;
    free(q);
    return head;
}

int main()
{
    n *head;
    n *sec;
    n *third;
    head = (n*)malloc(sizeof(n));
    sec = (n*)malloc(sizeof(n));
    third = (n*)malloc(sizeof(n));

    head->data=4;
    head->link=sec;

    sec->data=3;
    sec->link=third;

    third->data=2;
    third->link=NULL;
    printf("Before deletion\n");
    llt(head);
    printf("\n");
    printf("After deletion\n");
    head = deleteAtIndex(head, 2);
    llt(head);
    



return 0;

}