#include<stdio.h>

int main(){
  typedef struct person{
  char name[30];
  int age;
  float height;
  } per;
  per person1;
  sprintf(person1.name,"Appu Patil");
  person1.age = 19;
  person1.height = 5.8;

  per *ptr; //declaring a pointer as ptr
  ptr = &person1; //giving address to the pointer

  printf("--Employee details--\n");
  printf("\nName:\t%s",ptr->name);//using arrow(->) operator
  printf("\nAge:\t%d",ptr->age);
  printf("\nHeight:\t%f",ptr->height);
  printf("\n\nTIME OUT");
  printf("\n\nAddress of struct:%p",ptr);

return 0;
  
}