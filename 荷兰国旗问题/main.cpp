/*
	���⣺
		����һ���������У�ÿ������Ϊ�죨0�����ף�1��������2��������ɫ�е�һ�֡�
		��������в���˳����������洢�����һ��ʱ�临�Ӷ�ΪO(n)���㷨��ʹ
		����Щ���鰴�������˳���źã����ųɺ��������ͼ��
*/
#include<stdio.h>
#include"LinkList.h"
#include"SqList.h"
//˳���
/*
	��ʼʱiָ���ͷ��jָ���β��kָ���ͷ
	�ж�Ԫ��kֵ��Ϊ0��Ԫ��i������Ȼ��i����ƶ���k����ƶ���
	Ϊ1ʱ��k����ƶ���Ϊ2ʱk��j������k���ֲ��䣬j����ƶ���
	��Ϊk֮ǰ��Ԫ�ض����ź���
*/
void moveh1(SqList*& L)
{
	int i = 0;
	int j = L->length - 1;
	int k = 0;
	int temp;
	while (k <= j)
	{
		switch (L->data[k])
		{
		case 0:
			temp = L->data[k];
			L->data[k] = L->data[i];
			L->data[i] = temp;
			i++;
			k++;
			break;
		case 1:
			k++;
			break;
		case 2:
			temp = L->data[k];
			L->data[k] = L->data[j];
			L->data[j] = temp;
			j--;
			break;
		}
	}
}
//����
/*
	ʹ��3��������L,L1,L2��L����0��L1����1��L2����2.
	��������������������ӡ�
*/
void moveh2(LinkList*& L)
{
	LinkList* p = L->next;
	L->next = NULL;
	LinkList* r = L;
	LinkList* L1 = NULL, * r1 = NULL;
	LinkList* L2 = NULL, * r2 = NULL;
	while (p != NULL)
	{
		switch (p->data)
		{
		case 0:
			r->next = p;
			r = p;
			p = p->next;
			break;
		case 1:
			if (L1 == NULL)
			{
				L1 = p;
				r1 = p;
				p = p->next;
			}
			else
			{
				r1->next = p;
				r1 = p;
				p = p->next;
			}
			break;
		case 2:
			if (L2 == NULL)
			{
				L2 = p;
				r2 = p;
				p = p->next;
			}
			else
			{
				r2->next = p;
				r2 = p;
				p = p->next;
			}
			break;
		default:
			break;
		}
		if (r2 != NULL)
		{
			r2->next = NULL;
		}
		r->next = L1;
		r1->next = L2;
	}

}
int main()
{
	SqList* L;
	LinkList* L1;
	int a[13] = { 1,2,0,0,1,2,1,0,2,2,1,0,1 };
	CreateList(L, a, 13);
	DispSqList(L);
	moveh1(L);
	DispSqList(L);

	CreateListR(L1, a, 13);
	DispLinList(L1);
	moveh2(L1);
	DispLinList(L1);
}