/**********/
/*  排序  */
/*********/
#include<stdio.h>
#include<stdlib.h>
void Insertion_Sort(int *a, int n)
{
    for (int i = 1;i < n; i++)
    {
        int temp = a[i];
        int j;
        for (j = i ; j > 0 && a[j-1] > temp; --j);
        a[j] = temp;
    }
}
int main()
{
    int n;
    if (scanf("%d",&n) != 1)
        exit(-1);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d",&a[i]) != 1)
            exit(-1);
    }
        Insertion_Sort(a,n);
    for (int i = 0; i < n; i++)
    {
        if (i == n-1 )
            printf("%d",a[i]);
        else
            printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}