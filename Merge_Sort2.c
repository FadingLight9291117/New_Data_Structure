/*归并排序*/
#include<stdio.h>
/*二路归并*/
/*核心算法*/
void merge(int *A, int *TempA, int left, int right ,int rightEnd)
{
    int leftEnd = right - 1;
    int num = rightEnd - left + 1;
    int temp = left;
    while (left <= leftEnd && right <= rightEnd)
    {
        if (A[left] < A[right])
        {
            TempA[temp++] = A[left++];
        }
        else
        {
            TempA[temp++] = A[right++];
        }
    } 
    while (left <= leftEnd)
    {
        TempA[temp++] = A[left++];
    }
    while (right <= rightEnd)
    {
        TempA[temp++] = A[right++];
    }
    /*将临时数组的数据复制回原数组*/
    for (int i = 0; i <= num; i++)
    {
        A[rightEnd] = TempA[rightEnd];
        rightEnd--;
    }
}
/*非递归算法*/
void MergeSort(int* A, int* TempA, int n, int len)
{
    for (int i = 0; i < n; i += 2 * len)
    {
        
    }
}

int main()
{
    int A[6] = {1,4,6,7,2,5};
    int TempA[6];
    MergeSort(A, TempA, 0, 4, 5);
    for(int i = 0; i < 6; i++)
    {
        printf("%d ", A[i]);
    }
}