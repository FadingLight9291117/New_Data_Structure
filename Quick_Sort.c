#include<stdio.h>
/*插入排序*/
void Insert_Sort(int *A, int left, int right)
{
	for (int i = left + 1; i <= right; i++)
	{
		int temp = A[i];
		int j;
		for (j = i; j > 0; j--)
		{
			if (A[j - 1] > temp)	A[j] = A[j - 1];
			else break;
		}
		A[j] = temp;
	}
}
/*交换数字*/
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/*选主元*/
int Medium3(int *A, int left, int right)
{
	int center = (left + right) / 2;
	if (A[left] > A[center])	swap(&A[left], &A[center]);
	if (A[center] > A[right])	swap(&A[center], &A[right]);
	if (A[left] > A[center])	swap(&A[left], &A[center]);
	swap(&A[center], &A[right - 1]);
	return A[right - 1];
}
/*快速排序核心算法*/
void QuickSort(int *A, int left, int right)
{
	int CutOff = 5; // 阀值
	if (left - right > CutOff) // 长度大于阀值，使用快速排序
	{
		int pivot = Medium3(A, left, right);
		int i = left;
		int j = right - 1;
		while (1)
		{
			while (A[++i] < pivot);
			while (A[--j] > pivot);
			if (i < j)	swap(&A[i] ,&A[j]);
			else break;
		}
		swap(&A[i], &A[left - 1]);
		QuickSort(A, left, i - 1);
		QuickSort(A, i + 1, right);
	}
	else	Insert_Sort(A, left , right);
}
/*统一接口*/
void Quick_Sort(int *A, int n)
{
	QuickSort(A, 0, n - 1);
}
int main()
{
	int A[14] = {3,5,4,3,1,4,6,6,23,77,5,8,9,10};
	Quick_Sort(A, 14);
	for (int i = 0; i < 14; i++)	printf("%d ", A[i]);
	printf("\n");
	return 0;
}
