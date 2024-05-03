#include <stdio.h>
int main()
 {
    int n = 10;
    int a[10] = {5,4,10,7,2,1,8,3,6,9};
    int i,j,temp;
    for (i = 0; i < n; i++)
     {
        temp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > temp)
         {
            a[j + 1] = a[j];
            j--;
         }
        a[j + 1] = temp;
     }
    for (i = 0; i < n; i++)
     printf("%d, ",a[i]);
    printf("\n");
    return 0;
 }