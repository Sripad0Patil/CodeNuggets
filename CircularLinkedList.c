#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
  int data;
  struct Node* link;
}n;
void display(n* head)
{  
   n* p = head;
  do{
    printf("%d ",p->data);
    p=p->link;
  }while(p!=head);
}
n* insertAtFirst(n* head, int data)
{ 
  n* temp=(n*)malloc(sizeof(n));//a new node to insert
  temp->data=data;
  n* p=head->link;// pointer for traversing
  while(p->link!=head)
  {
    p=p->link;
  }
  p->link=temp;
  temp->link=head;
  head=temp;
  return head;
}
n* insertAtLast(n* head, int data)
{ 
  n* temp=(n*)malloc(sizeof(n));//a new node to insert
  temp->data=data;
  n* p=head->link;// pointer for traversing
  while(p->link!=head)
  {
    p=p->link;
  }
  p->link=temp;
  temp->link=head;
  temp=head;
  return head;
}
int main()
{
  n* head=(n*)malloc(sizeof(n));
  n* first=(n*)malloc(sizeof(n));
  n* second=(n*)malloc(sizeof(n));

  head->data=0;
  head->link=first;

  first->data=1;
  first->link=second;

  second->data=2;
  second->link=head;
  printf("Insert at first: ");
  head=insertAtFirst(head, -1);
  display(head);
  printf("\nInsert at last: ");
  head=insertAtLast(head, 3);
  display(head);

return 0;
}