#include<stdio.h>
int main()
{
    int a[6]={ 5,4,10,6,2,1};
    int i,j,temp;
    int n = 6;
    for (i= 1; i< n ;i++)
    {
        temp = a[i];
        j= i - 1;
        while ( j>= 0 && a[j]> temp)
        {
            a[j + 1]= a[j];
            j--;
        }
        a [j + 1]= temp;
    }
    for (i= 0; i<n ; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}