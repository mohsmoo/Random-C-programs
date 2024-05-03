#include<stdio.h>
int main()
{
    int a[10]={2,1,5,4,10,3,7,9,8,6};
    int i,j,temp;
    int min= 0;
    int n = 10;
    for (i = 0;i<n - 1; i++)
    {
        int min = i;
        for(j = i+ 1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min = j;
            }
            if (min!= i)
            {
                temp = a[min];
                a[min]= a[i];
                a[i]= temp;
            }
        }
    }
    for (i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}