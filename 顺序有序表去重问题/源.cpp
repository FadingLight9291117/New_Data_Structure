/*
	���⣺ȥ����������ظ�Ԫ��
	��������Ϊ�����ظ�Ԫ���ڽ���k��¼�ظ�Ԫ�ظ���������Ԫ����ǰƽ��������ǰ�档
*/
#include<stdio.h>
#include"˳���.h"

int main()
{
	int a[8] = { 1,1,2,2,2,3,3,3 };
	SqList* L;
	CreateSqList(L, a, 8);
	int k = 1;
	for (int i = 1; i < L->length; i++)
	{
		if (L->data[i] != L->data[i - 1])
		{
			k++;
			L->data[k-1] = L->data[i];
		}
	}
	L->length = k;
	DispSqList(L);
}