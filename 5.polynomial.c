#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coef;
    int exp;
    struct node *next;
};
void create (struct node **head, int coef, int exp)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> coef = coef;
    newNode -> exp = exp;
    newNode -> next = NULL;
    if (*head == NULL)
     {
        *head = newNode;
     }
    else
     {
        struct node *temp = *head;
        while (temp -> next != NULL)
         {
            temp = temp -> next;
         }
        temp -> next = newNode;
     }
}
void display (struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
     {
        printf ("%dx^%d + ",temp -> coef, temp -> exp);
        temp = temp -> next;
     }
    printf ("\n");
}   
struct node *add (struct node *head1,struct node *head2)
{
    struct node *head3 = NULL;
    struct node *temp1 = head1;
    struct node *temp2 = head2;
     while (temp1 != NULL && temp2 != NULL)
      {
        if (temp1 -> exp == temp2 -> exp)
         {
            create (&head3, temp1 -> coef + temp2 -> coef, temp1 -> exp);
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
         }
        else if (temp1 -> exp > temp2 -> exp)
         {
            create (&head3, temp1 -> coef, temp1 -> exp);
            temp1 = temp1 -> next;
         }
        else 
         {
            create (&head3, temp2 -> coef, temp2 -> exp);
            temp2 = temp2 -> next;
         }
      }
     while (temp1 != NULL)
      {
        create (&head3, temp1 -> coef, temp1 -> exp);
        temp1 = temp1 -> next;
      }
     while (temp2 != NULL)
      {
        create (&head3, temp2 -> coef, temp2 -> exp);
        temp2 = temp2 -> next;
      }
    return head3;
}
int main()
{
  struct node *head1 = NULL;
  struct node *head2 = NULL;
  struct node *head3 = NULL;

  create (&head1, 5, 2);
  create (&head1, 3, 1);
  create (&head1, 2, 0);

  create (&head2, 7, 3);
  create (&head2, 4, 2);
  create (&head2, 1, 0); 

  printf ("First Polynomial: ");
  display (head1);

  printf ("Second Polynomial: ");
  display (head2);

  head3 = add (head1, head2);

  printf ("Resultant Polynomial: ");
  display (head3);
  return 0; 
}