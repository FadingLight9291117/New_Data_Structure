/*
	���⣺�����ȳ�����������˳���ģ��ҳ���������A��B����λ����
	����	��	1.����ż����λ�����n��
			2.��һ�Ƚ�ֱ��nΪֹ��
*/
#include<stdio.h>
#include"˳���.h"
int Max(int a, int b)
{
	return a >= b ? 1 : 0;
}
int M_Search(SqList* L1, SqList* L2)
{
	int len = L1->length*2;
	int middle;
	int result = 0;;
	if (len % 2 == 0)		//����ż������λ�����
	{
		middle = len / 2;
	}
	else
	{
		middle = len / 2 + 1;
	}
	//printf("%d", middle);
	int m = 0, n = 0;
	for (int i = 0; i < middle; i++)	//ѭ���������ҳ���len����
	{
		if (Max(L1->data[m], L2->data[n]))
		{
			result = L2->data[n];
			n++;			
		}
		else
		{
			result = L1->data[m];
			m++;
		}
	}
	return result;
}
int main()
{
	int a1[5] = { 11,13,15,17,19 };
	int a2[5] = { 2,4,6,8,20 };
	SqList* L1, * L2;
	CreateSqList(L1, a1, 5);
	CreateSqList(L2, a2, 5);
	printf("%d", M_Search(L1, L2));
}