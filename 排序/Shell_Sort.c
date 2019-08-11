/****************/
/*  希尔排序    */
/***************/
#include <stdio.h>
void Shell_Sort(int *a, int n)
{
    for (int i = n / 2; i > 0; i /= 2)                  // 希尔增量序列
    {
        for (int j = i; j < n; j++)                     // 插入排序
        {
            int temp = a[j];
            int k;
            for (k = j; k >= i && a[k - i] > temp; k -= i)
            {
                a[k] = a[k - i];
            }
            a[k] = temp;
        }
    }
}

int main(int argc, char const *argv[])
{
    int a[20] = {2, 4, 6, 1, 12, 42, 67, 4, 89, 76, 3, 9, 12, 32, 56, 54, 23, 83, 14, 28};
    Shell_Sort(a, 20);
    for (int i = 0; i < 20; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
