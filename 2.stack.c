#include <stdio.h>
#include <stdlib.h>
#define max 5
int top=-1,stack[max],item;
void push(int item)
 {
  if(top==max-1)
   {
    printf("stack overflow\n");
    return;
   }
  else
   {
    top+=1;
    stack[top]=item;
   }
 }
void pop()
 {
  if(top<0)
   {
    printf("stack underflow\n");
   }
  else
   {
    item=stack[top];
    top-=1;
    printf("deleted item is %d\n",item);
   }
 }
void display()
 {
  int i;
  if(top<0)
   {
    printf("stack is empty\n");
   }
  else
  {
   printf("the stack is:\n");
   for(i=0;i<=top;i++)
    {
     printf("%d\n",stack[i]);
    }
  }
 }
int main()
 {
  int choice,num;
  while(1)
  {
   printf("\n**** Stack Menu ****\n");
   printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
   printf("Enter choice (1-4): ");
   scanf("%d",&choice);
   switch(choice)
    {
     case 1:
      printf("enter number to push: ");
      scanf("%d",&num);
      push(num);
      break;
     case 2:
      pop();
      break;
     case 3:
      display();
      break;
     case 4:
      exit(0);
      break;
     default:
      printf("enter valid choice\n");
      break;
    }
  }
  return 0;
 }
