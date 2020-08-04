/***************/
/*  快速排序    */
/**************/

#include <stdio.h>

/*a,b交换*/
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*选主元*/
/*首，尾和中间的三个数比较*/
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
    swap(&a[center], &a[right - 1]); // 将主元放入倒数第二个位置
    return a[right - 1];
}

/*插入排序*/
void InsertionSort(int *a, int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int temp = a[i]; // 摸下一张牌
        int j;
        for (j = i; j > left && a[j - 1] > temp; j--)
        {
            a[j] = a[j - 1]; // 移出空位，往后移一位
        }
        a[j] = temp; // 放入新牌
    }
}

/*排序核心算法*/
void QuickSort(int *a, int left, int right)
{
    int Cutoff = 5;             // 定义一个阀值，当待排序列长度小于阀值时，调用插入排序
    if (Cutoff <= right - left) // 快速排序
    {
        int pivot = Medium3(a, left, right); // 选主元
        int i = left;
        int j = right - 1;
        while (1)
        {
            while (a[++i] < pivot)
                ;
            while (a[--j] > pivot)
                ;
            if (i < j)
                swap(&a[i], &a[j]);
            else
                break;
        }
        swap(&a[i], &a[right - 1]);
        QuickSort(a, left, i - 1);
        QuickSort(a, i + 1, right);
    }
    else // 到达阀值，调用插入排序
    {
        InsertionSort(a, left, right);
    }
}

/*统一接口*/
void Quick_Sort(int *a, int n)
{
    QuickSort(a, 0, n - 1);
}
/*测试*/
#include <stdlib.h>
#define N 500000
int main(int argc, char const *argv[])
{
    int a[N];
    for (int i = 0; i < N; i++)
    {
        a[i] = rand();
    }
    Quick_Sort(a, N);
    for (int i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}