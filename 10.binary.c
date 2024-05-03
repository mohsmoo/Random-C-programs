#include<stdio.h>
int main()
 {
    int arr[5], key, beg = 0, end = 4, mid = (beg + end)/2;
    printf("enter 5 numbers in ascending order:\n");
    for(int i = 0; i < 5; i++)
     {
        scanf("%d", &arr[i]);
     }
    printf("enter number to be searched: ");
    scanf("%d", &key);
    while(beg <= end)
     {
        if(key == arr[mid])
         {
            printf("the position is %d\n", mid+1);
            break;
         }   
        else if(key < arr[mid])
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
        printf("number not found\n");
     }
    return 0;
 }