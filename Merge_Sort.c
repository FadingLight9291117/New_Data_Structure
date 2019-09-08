#include<stdio.h>
#include<stdlib.h>
void MergeSortCore(int *A, int *TempA, int Left, int Right, int RightEnd)
{
    int LeftEnd = Right - 1;
    int num = RightEnd - Left + 1;
    int temp = Left;
    while (Left <= LeftEnd && Right <= RightEnd)
    {
        if (A[Left] < A[Right])
        {
            TempA[temp++] = A[Left++];
        }
        else
        {
            TempA[temp++] = A[Right++];
        }
    }
    while (Left <= LeftEnd)
    {
        TempA[temp++] = A[Left++];
    }
    while (Right <= RightEnd)
    {
        TempA[temp++] = A[Right++];
    }
    for (int i = 0; i < num; i++ , RightEnd--)
    {
        A[RightEnd] = TempA[RightEnd];
    }
}
void MergeSortByRecurse(int *A, int *TempA, int Left, int RightEnd)
{
    int center = (Left + RightEnd) / 2;
    if (Left < RightEnd)
    {
        MergeSortByRecurse(A, TempA, Left, center);
        MergeSortByRecurse(A, TempA, center + 1, RightEnd);
        MergeSortCore(A, TempA, Left, center + 1, RightEnd);
    }
}
void Merge_Sort_Recurse(int *A, int N)
{
    int *TempA = (int*)malloc(sizeof(int) * N);
    MergeSortByRecurse(A, TempA, 0, N - 1);
    free(TempA);
    TempA = NULL;
}
void MergeSortCore1(int *A, int *TempA, int Left, int Right, int RightEnd)
{
    int LeftEnd = Right - 1;
    int num = RightEnd - Left + 1;
    int temp = Left;
    while (Left <= LeftEnd && Right <= RightEnd)
    {
        if (A[Left] < A[Right])
        {
            TempA[temp++] = A[Left++];
        }
        else
        {
            TempA[temp++] = A[Right++];
        }
    }
    while (Left <= LeftEnd)
    {
        TempA[temp++] = A[Left++];
    }
    while (Right <= RightEnd)
    {
        TempA[temp++] = A[Right++];
    }
}

/*len 是当前有序序列的长度*/
void MergeSort(int *A, int *TempA, int N, int len)
{
    int i;
    for (i = 0; i + 2*len <= N; i += 2*len)
    {
        MergeSortCore1(A, TempA, i, i + len, i + 2*len - 1);
    }
    if (i + len < N)
    {
        MergeSortCore1(A, TempA, i, i + len, N - 1);
    }
    else
    {
        for (; i < N; i++)
        {
            TempA[i] = A[i];
        }
    }
}
void Merge_Sort(int *A, int N)
{
    int *TempA = (int *)malloc(sizeof(int)*N);
    int i = 1;
    while (i < N)
    {
        MergeSort(A, TempA, N, i);
        i *= 2;
        MergeSort(TempA, A, N, i);
    }
}
int main(int argc, char const *argv[])
{
    int A[13] = {2,4,64,23,4,76,23,54235,23,11,2,5,8};
    Merge_Sort(A, 13);
    for (int i = 0; i < 13; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}
