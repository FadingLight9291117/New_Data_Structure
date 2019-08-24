#include<stdio.h>
void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int Medium3(int *a, int left, int right)
{
    int center = (left + right) / 2;
    if (a[center] < a[left])
    {
        Swap(&a[center], &a[left]);
    }
    if (a[right] < a[center])
    {
        Swap(&a[center], &a[right]);
    }
    if (a[center] < a[left])
    {
        Swap(&a[center], &a[left]);
    }
    Swap(&a[center], &a[right - 1]);
    return a[right - 1];
}
void Insertion_Sort(int *a, int left, int right)
{   
    int temp;
    for (int i = left + 1; i <= right; ++i)
    {
        temp = a[i];
        int j;
        for (j = i; j > left && a[j - 1] > temp; --j)
        {
            a[j] = a[j - 1];
        }
        a[j] = temp; 
    }
}
void QuickSort(int *a, int left, int right)
{
    int CutOff = 8;
    if (right - left >= CutOff)
    {
        int pivot = Medium3(a, left, right);
        int i = left;
        int j = right - 1;
        while (1)
        {
            while (a[++i] < pivot);
            while (a[--j] > pivot);
            if (i < j)
            {
                Swap(&a[i], &a[j]);
            }        
            else
            {
                break;
            }
        }
        Swap(&a[i], &a[right - 1]);
        QuickSort(a, left, i-1);
        QuickSort(a, i+1, right);
    }
    else
    {
        Insertion_Sort(a, left, right);
    }
}
void Quick_Sort(int *a,int n)
{
    QuickSort(a,0,n-1);
}

int main(int argc, char const *argv[])
{
    int a[20] = {43,12,6,4,756,43,233,77,54,3,4,90,0,87,34,-1,-23,4,44,-100};
    Quick_Sort(a,20);
    for (int i = 0; i < 20; ++i)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
