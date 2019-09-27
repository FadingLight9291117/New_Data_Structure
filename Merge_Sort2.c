/*归并排序*/
#include<stdio.h>
#include<stdlib.h>
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
}
/*非递归算法*/
void MergeSort(int* A, int* TempA, int n, int len)
{
	int i;
    for (i = 0; i + 2 * len <= n; i += 2 * len)
    {
        merge(A, TempA, i, i + len, i + 2 * len - 1);
    }
	if (i + len <= n)
	{
		merge(A, TempA, i, i + len, n - 1);
	}
	else
	{
		while (i < n)
		{
			TempA[i] = A[i];
			i++;
		}
	}
}
void Merge_Sort(int* A, int n)
{
	int* TempA = (int*)malloc(sizeof(int) * n);
	int len = 1;
	while (len < n)
	{
		MergeSort(A, TempA, n, len);
		len *= 2;
		MergeSort(TempA, A, n, len);
	}
}

int main()
{
    int A[6] = {1,4,6,7,2,5};
	Merge_Sort(A, 6);
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", A[i]);
	}
}
