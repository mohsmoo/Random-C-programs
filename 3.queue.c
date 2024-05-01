#include<stdio.h>
#include<stdlib.h>
#define MAX_size 5
int queue[MAX_size];
int rear = -1;
int front = -1;
void insert();
void delete();
void display();

int main()
{
    int choice,num;
    while(1)
    {
        printf("1.insert\n2.remove\n3.display\n4.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("enter a number to insert: ");
            scanf("%d",&num);
            insert(num);
            break;
            case 2: 
            delete(num);
            break;
            case 3:display ();
            break;
            case 4:exit(0);
            break;
            default:printf("invalid choice\n");
        }
    }
}
void insert (int num)
{
    if (rear == MAX_size - 1)
    {
        printf("overflow\n");
    }
    else
    {
        front = 0;
        rear++;
        queue[rear]=num;
    }
}
void delete()
{
    if (front == -1 && rear == -1)
    {
        printf("underflow\n");
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
        printf("only one element is present ");
    }
    else
    {
        printf("the element is %d ",queue[front]);
        printf("\n");
        front = front + 1;
        
    }
}
void display()
{
    int i;
    if(front == -1 && rear == -1)
    {
        printf("no elements to display ");
    }
    else
    {
        printf("the elements in queue are:");
        for(i = front; i <= rear; i++)
        {
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}