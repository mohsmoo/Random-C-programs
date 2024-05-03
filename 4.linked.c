#include<stdio.h>
#include<stdlib.h>
struct node
 {
  int data;
  struct node *next;
 };
struct node *head;
void startinsert()
 {
  struct node *ptr;
  int item;
  ptr=(struct node *)malloc(sizeof(struct node *));
  if(ptr==NULL)
   {
    printf("overflow\n");
   }
  else
   {
    printf("enter value:\n");
    scanf("%d",&item);
    ptr->data = item;
    ptr->next = head;
    head=ptr;
    printf("node added\n");
   }
 }
void endinsert()
 {
  struct node *ptr,*temp;
  int item;
  ptr=(struct node *)malloc(sizeof(struct node));
  if(ptr==NULL)
   {
    printf("overflow\n");
   }
  else
   {
    printf("enter value:\n");
    scanf("%d",&item);
    ptr->data = item;
    if(head==NULL)
     {
      ptr->next=NULL;
      head=ptr;
      printf("node added\n");
     }
    else
     {
      temp = head;
      while(temp -> next != NULL)
       {
	temp=temp->next;
       }
      temp->next=ptr;
      ptr->next=NULL;
      printf("node added\n");
     }
   }
 }
void midinsert()
 {
  int i,loc,item;
  struct node *ptr,*temp;
  ptr=(struct node *)malloc(sizeof(struct node));
  if(ptr==NULL)
   {
    printf("overflow\n");
   }
  else
   {
    printf("enter value:\n");
    scanf("%d",&item);
    ptr->data=item;
    printf("enter the node after which you want to add\n");
    scanf("%d",&loc);
    temp=head;
    for(i=0;i<loc-1;i++)
     {
      temp=temp->next;
      if(temp==NULL)
       {
	printf("end cant insert\n");
	return;
       }
     }
      ptr->next=temp->next;
      temp->next=ptr;
      printf("node added\n");
   }
 }
void startdelete()
 {
  struct node *ptr;
  if(head==NULL)
   {
    printf("the list is empty\n");
   }
  else
   {
    ptr=head;
    head=head->next;
    free(ptr);
    printf("node deleted\n");
   }
 }
void enddelete()
 {
  struct node *ptr,*ptr1;
  if(head==NULL)
   {
    printf("the list is empty\n");
   }
  else if(head->next==NULL)
   {
    head=NULL;
    free(head);
    printf("only node of the list is deleted\n");
   }
  else
   {
    ptr=head;
    while(ptr->next != NULL)
     {
      ptr1=ptr;
      ptr=ptr->next;
     }
    ptr1->next=NULL;
    free(ptr);
    printf("node deleted\n");
   }
 }
void middelete()
 {
  struct node *ptr,*ptr1;
  int loc,i;
  printf("enter the node after which you want to delete\n");
  scanf("%d",&loc);
  ptr=head;
  for(i=0;i<loc;i++)
   {
    ptr1=ptr;
    ptr=ptr->next;
    if(ptr==NULL)
     {
      printf("end cant delete\n");
      return;
     }
   }
  ptr1->next=ptr->next;
  free(ptr);
  printf("deleted node %d\n",loc+1);
 }
void display()
 {
  struct node *ptr;
  ptr=head;
  if(ptr==NULL)
   {
    printf("the list is empty\n");
   }
  else
   {
    printf("values are:\n");
    while(ptr!=NULL)
     {
      printf("%d\n",ptr->data);
      ptr=ptr->next;
     }
   }
 }
int main()
 {
  int choice;
  while(1)
   {
    printf("menu:\n");
    printf("choose one option:\n");
    printf("1.insert at start\n2.insert at last\n3.insert in middle\n4.delete at start\n5.delete at end\n6.delete at mid\n7.display\n8.exit\n");
    printf("enter choice: ");
    scanf("%d",&choice);
    switch(choice)
     {
      case 1:
       startinsert();
       break;
      case 2:
       endinsert();
       break;
      case 3:
       midinsert();
       break;
      case 4:
       startdelete();
       break;
      case 5:
       enddelete();
       break;
      case 6:
       middelete();
       break;
      case 7:
       display();
       break;
      case 8:
       exit(0);
       break;
      deafult:
       printf("invalid choice\n");
     }
   }
 }