#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int size;
    int top;
    int* arr;
} st;

int isFULL(st* ptr)
{
    if(ptr->top == ptr->size - 1)
    {
        printf("\nStack is full.");
        return 1;
    }
    return 0;
}

int isEMPTY(st* ptr)
{
    if(ptr->top == -1)
    {
        printf("\nStack is empty.");
        return 1;
    }
    return 0;
}
void push(st* ptr, int value)
{
  if(isFULL(ptr))
  {
    printf("\nStack overflow!! connot push %d in stack",value);
  }
  ptr->top++;
  ptr->arr[ptr->top]=value;
}
int pop(st* ptr)
{
  if(isEMPTY(ptr)){
    printf("\nStack undflow");
    
  }
  int val=ptr->arr[ptr->top];
  ptr->top=ptr->top-1;
  ptr->top--;
  return val;
}
int peek(st* sa, int p)
{
  int index=sa->top-p+1;
  if(index<0)
  {
    printf("\nInvalid");
    return -1;
  }
  {
    return sa->arr[index];
  }
}
int S_top(st* sa)
{
  if(isEMPTY(sa))
  {
    return -1;
  }
  return sa->arr[sa->top];
}
int S_bottom(st* sa)
{
   if(isEMPTY(sa))
  {
    return -1;
  }
  return sa->arr[0];
}
int main()
{
    st* s; 
    s = (st*)malloc(sizeof(st));
    s->size = 10;
    s->top = -1;
    s->arr = (int*)malloc(s->size * sizeof(int));
    s->arr[0] = 1;
  push(s, 10);//-->bottom
  push(s, 12);
  push(s, 13);
  push(s, 14);
  push(s, 15);
  push(s, 15);
  push(s, 15);
  push(s, 16);
  push(s, 16);//-->top
  // push(s, 16);
  // push(s, 17);
  for(int i=1;i<=s->top+1;i++)
  {
    printf("\nElement at position %d is %d",i,peek(s,i));
  }
  printf("\nTop element: %d",S_top(s));
  printf("\nBottom element: %d",S_bottom(s));

  

    return 0;
}