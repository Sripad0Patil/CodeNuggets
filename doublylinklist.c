#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* prev;
    struct Node* link;
}n;
void llt(n *ptr)
{
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
}
n* insert(n* head, int data)
{
    n* ptr=(n*)malloc(sizeof(n));
    ptr->prev=NULL;
    ptr->link=head;
    ptr->data=data;
    return ptr;

}
n* insertAtEnd(n* head, int data)
{
    n* ptr=(n*)malloc(sizeof(n));
    n* p=head->link;
    while(p->link!=NULL)
    {
        p=p->link;  
    }
    ptr->data=data;
    p->link=ptr;
    ptr->prev=p;
    ptr->link=NULL;
    return head;
}
n* deleteAtEnd(n* head)
{
    n* p=head;
    n* q=head->link;
    while(q->link!=NULL)
    {
        p=p->link;
        q=q->link;
    }
    p->link=NULL;
    free(q);
    return head;
}
n* delete(n* head)
{
    n* temp=head;
    head=head->link;
    free(temp);
    head->prev=NULL;
    return head;
}
int main()
{
    n*head=(n*)malloc(sizeof(n));
    n*first=(n*)malloc(sizeof(n));
    n*sec=(n*)malloc(sizeof(n));

    head->prev=NULL;
    head->data=1;
    head->link=first;

    first->prev=head;
    first->data=2;
    first->link=sec;

    sec->prev=first;
    sec->data=3;
    sec->link=NULL;
    printf("Original: ");
    llt(head);
    printf("\nAfter insertion at beginnig: ");
    head = insert(head, 0);
    llt(head);
    printf("\nAfter insertion at end: ");
    head = insertAtEnd(head, 7);
    llt(head);
    printf("\nAfter deletion at beginnig: ");
    head = delete(head);
    llt(head);
    printf("\nAfter deletion at end:  ");
    head = insertAtEnd(head, 7);
    llt(head);
    printf("\nAfter deletion at beginnig: ");
    head = delete(head);
    llt(head);
    printf("\nAfter deletion at end:  ");
    head = deleteAtEnd(head);
    llt(head);



}