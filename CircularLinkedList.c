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
  if(head!=NULL){

   n* p = head;
  do{
    printf("%d ",p->data);
    p=p->link;
  }while(p!=head);
  }
  else{
    printf("\nThe queue is empty");
  }
}
void create(int val)
{
  if(head==NULL)
  {
    head = (n*)malloc(sizeof(n));
    head->data=val;
    head->link=head;
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



n* deleteAtFirst(n* head)
{

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
  int ch;
  printf("1.Create\n2.Insert at first\n3.Insert at end\n4.Delete at first\n5.Delete at end\n6.Display\n7.Exit");
  while(1)
  {
    printf("\nEnter your choice: ");
    scanf("%d",&ch);
    switch (ch)
    {
      case 1:
      {
        int val;
        printf("\nEnter a value to create: ");
        scanf("%d",&val);
        create(val);
        break;
      }
      case 2:
      {
        int val;
        printf("\nEnter a value to insert: ");
        scanf("%d",&val);
        head=insertAtFirst(head,val);
        break;
      }
      case 3:
      {
        int val;
        printf("\nEnter a value to insert: ");
        scanf("%d",&val);
        head=insertAtLast(head,val);
        break;
      }
      case 4:
      {
        head=deleteAtFirst(head);
        break;
      }
      case 5:
      {
        head=deleteAtEnd(head);
        break;
      }
      case 6:
      {
        display(head);
        break;
      }
      case 7:
      {
        printf("Exiting....");
        exit(0);
      } 

      default:
      {
        printf("\nInvalid choice.");
      }
    }
  }

return 0;
}