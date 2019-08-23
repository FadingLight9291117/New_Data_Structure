/***************/
/*  快速排序    */
/**************/
#include<stdio.h>
/*插入排序*/
void InsertionSort(int *a,int left, int right)
{
    for (int i = left; i <= right; i++)
    {
        int temp = a[i];                        // 摸下一张牌
        int j;
        for (j = i; j>0 && a[j-1] > temp; j--)
        {
            a[j] =  a[j-1];                     // 移出空位，往后移一位
        }
        a[j] = temp;                            // 放入新牌 
    }
}
/*a,b交换*/
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
/*选主元*/
int Medium3(int *a, int left, int right) 
{
    int center = (left + right) / 2;
    if (a[left] > a[center]) 
    {
        swap(&a[left], &a[center]);
    }
    if (a[center] > a[right]) 
    {
        swap(&a[center], &a[right]);
    }
    if (a[left] > a[center]) 
    {
        swap(&a[center], &a[left]);
    }
    swap(&a[center], &a[right-1]);
    return a[right-1];
}
/*排序核心算法*/
void QuickSort(int *a, int left, int right) 
{
   if (right - left > 5)
   { 
        int pivot = Medium3(a, left, right);   // 选主元
        int i = left + 1;
        int j = right - 2;
        while (1)
        {
            while (a[i] < pivot)
                i++;
            while (a[j] > pivot)
                j--;
            if (i > j)
                break;
            swap(&a[i],&a[j]);
        }
        swap(&a[i], &a[right-1]);
        QuickSort(a,left,i-1);
        QuickSort(a,i+1,right);
   }
   else
   {
       InsertionSort(a,left,right);
   }
   
}

/*统一接口*/
void Quick_Sort(int *a, int n)
{
    QuickSort(a,0,n-1);
}

int main(int argc, char const *argv[])
{
    int a[15] = {2,42,1,6,43,32,543,12,65,278,9,222,34,89,76};
    Quick_Sort(a, 15);
    for (int i = 0; i < 15; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    
    return 0;
}
