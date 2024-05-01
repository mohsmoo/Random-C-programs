#include<stdio.h>
int main()
{
    int a[6]={ 7,4,10,8,3,1};
    int i,j,temp;
    int min= 0;
    int n = 6;
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
    return 0;
}