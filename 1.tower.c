#include<stdio.h>
void tower(int n,char source, char des, char aux)
 {
  if(n==0)
   {
       printf("stack underflow\n");
       return;
   }
  if(n==1)
   {
       printf("move disk 1 from %c to %c\n",source, des);
       return;
   }
  else
   {
       tower(n-1,source,aux,des);
       printf("move disk %d from %c to %c\n",n,source,des);
       tower(n-1,aux,des,source);
   }
 }
int main()
 {
     int n;
     printf("number of disk: ");
     scanf("%d",&n);
     printf("sequence to follow:\n");
     tower(n,'A','C','B');
     return 0;
 }