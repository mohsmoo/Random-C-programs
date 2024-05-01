#include<stdio.h>
int main()
 {
  int array[5],i,key,beg=0,end=4,mid;
  printf("Enter 5 numbers in ascending order: ");
  for(i=0;i<5;i++)
   {
    scanf("%d",&array[i]);
   }
  printf("Enter the number to be searched: ");
  scanf("%d",&key);
  mid=(beg+end)/2;
  while(beg <= end)
  {
   if(key == array[mid])
    {
     printf("the position is %d",mid+1);
     break;
    }
   else if(key < array[mid])
    {
     end = mid - 1;
    }
   else
    {
     beg = mid + 1;
    }
   mid = (beg + end)/2;
   }
  if(beg > end)
   {
    printf("number not found");
   }
  return 0;
 }