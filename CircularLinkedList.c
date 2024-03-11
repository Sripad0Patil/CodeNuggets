#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
  int data;
  struct Node* link;
}n;

n* head=NULL;
n* tail=NULL;

void display(n* head)
{  
  if(head){

   n* p = head;
  do{
    printf("%d ",p->data);
    p=p->link;
  }while(p!=head);
  }
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
  tail = temp;  
  return head;
}

// n* lst(n* head, int data)
// {
//   n* temp=(n*)malloc(sizeof(n));
//   temp->data=data;
//   n* tail = head->link;
//   while(tail->link!=head)
//   {
//     tail=tail->link;
//   }
//   tail->link=temp;
//   temp->link=head;
//   temp=head;
//   return head;
// }

n* deleteAtFirst(n* head)
{
  // int v;
  // while(head!=NULL)
  // {
  //   n* temp=head;
  //   head=head->link;
  //   tail->link=head;
  //   //v=temp->data;
  //   free(temp);
  //   return head;
  // }
  if(head->link == head) {
    free(head);
    return NULL; 
  }
  n * temp = head->link;
  free(head);
  tail->link = temp;
  return temp;
}

n* deleteAtEnd(n* head)
{
  n* q=head;
  n* p=head->link;
  while(p->link!=head)
  {
    q=q->link;
    p=p->link;
  }
  free(p);
  q->link=head;
  tail = q;
  return head;
}

int main()
{
  n* head=(n*)malloc(sizeof(n));
  n* first=(n*)malloc(sizeof(n));
  n* sec=(n*)malloc(sizeof(n));
  n* thi=(n*)malloc(sizeof(n));
  n* fo=(n*)malloc(sizeof(n));
  n* tail=(n*)malloc(sizeof(n));
  head->data=0;
  head->link=first;

  first->data=1;
  first->link=sec;

  sec->data=2;
  sec->link=thi;

  thi->data=3;
  thi->link=fo;

  fo->data=4;
  fo->link=tail;
  
  tail->data=5;
  tail->link=head;

  printf("Original: ");
  display(head);
  printf("\nInsert at first: ");
  head=insertAtFirst(head, -1);
  display(head);
  printf("\nInsert at last: ");
  head=insertAtLast(head,6);
  display(head);

  printf("\nDelete at first: ");
  head=deleteAtFirst(head);
 
  
  display(head);
  printf("\nDelete at last: ");
  head=deleteAtEnd(head);
  display(head);

return 0;
}