/*
	=============2019.4.12===============
	1.����˳���ṹ������Ԫ��int���ͣ�
	2.����˳���Ļ������㡣
	=====================================
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

typedef struct
{
	int data[MAX_SIZE];
	int length;
}SqList;

//1. ����˳��� 
//���崴��˳���
//���÷��š�&�������β�L��ǰ�档
//����Ͳ�����ʹ�á�&�������۲���ֵ�Ƿ�ı� 
void CreateList(SqList*& L, int a[], int n)
{
	int i;
	L = (SqList*)malloc(sizeof(SqList));
	for (i = 0; i < n; i++)
	{
		L->data[i] = a[i];
	}
	L->length = n;
}

//2.˳�����������㷨 
//��1����ʼ�����Ա�InitList(L) 
//������Ľ��ʱ����һ���յ����Ա�L��ʵ����ֻ�轫length��Ա����Ϊ0���ɡ� 
void InitList(SqList*& L)
{
	L = (SqList*)malloc(sizeof(SqList));
	L->length = 0;
}
//��2���������Ա�DestroyList(L)
//������Ľ��ʱ�ͷ����Ա�Lռ�õ��ڴ�ռ䡣 
void DestoryList(SqList*& L)
{
	free(L);
	L = NULL;
}
//��3���ж��Ƿ�Ϊ�ձ�ListEmpty(L)
//�����㷵��һ��ֵ��ʾL�Ƿ�Ϊ�ձ���Ϊ�ձ�
//�򷵻�true�����򷵻�false 
bool ListEmpty(SqList* L)
{
	return (L->length == 0);
}
//(4)�����Ա�ı�Listlength(L)
//�����㷵��˳���L�ĳ��ȡ�ʵ��ֻ�践��length��Ա��ֵ���ɡ� 
int ListLength(SqList * L)
{
	return L->length;
}
//(5)������Ա�DispList(L)
//�����㵱���Ա�L��Ϊ��ʱ��˳����ʾL�и�Ԫ�ص�ֵ�� 
void DispSqList(SqList * L)
{
	int i;
	if (ListEmpty(L))	return;
	for (i = 0; i < L->length; i++)
	{
		printf("%d", L->data[i]);
	}
	printf("\n");
}
//��6����ĳ������Ԫ�ص�ֵGetElem(L,i,e)
//�����㷵��L�е�i(1<=i<=ListLength(L))��Ԫ�ص�ֵ�������e�� 
bool GetElem(SqList * L, int i, int& e)
{
	if (i<1 || i>L->length)	return false;
	e = L->data[i];
	return true;
}
//��7����Ԫ��ֵ����LocateElem(L,e)
//��������ҵ�һ��ֵ����e��ȵ�Ԫ�ص��߼�λ����������Ԫ�ز����ڣ��򷵻�ֵΪ0 
int LocateElem(SqList * L, int e)
{
	int i = 0;
	while (i <= L->length && L->data[i] != e)
	{
		i++;
	}
	if (i >= L->length) return 0;
	return i + 1;
}
//��8����������Ԫ��ListInsert��L,i,e)
//��������˳���L�ĵ�i(1<=i<=ListLength(L)+1)��λ���ϲ����µ�Ԫ��e�� 
bool ListInsert(SqList * &L, int i, int e)
{
	int j;
	if (i<1 || i>L->length)	return false;
	i--;
	for (j = L->length; j > i; j--)
	{
		L->data[j] = L->data[j - 1];
	}
	L->data[i] = e;
	L->length++;
	return true;
}
//�� 9��ɾ������Ԫ��ListDelete(L,i,e)
//������ɾ��˳���L�ĵ�i(i<=i<=ListLength(L))��Ԫ�� 
bool ListDelete(SqList * &L, int i, int& e)
{
	int j;
	if (i<1 || i>L->length)	return false;
	i--;
	e = L->data[i];
	for (j = i; j < L->length; j++)
	{
		L->data[j] = L->data[j + 1];
	}
	L->length--;
	return true;
}

/*
	=================2019.4.12================
	���⣺ɾ��˳���������ֵΪx������Ԫ�ء�
	Ҫ��ʱ�临�Ӷ�O(n),�ռ临�Ӷ�ΪO(1)
					�����㷨��
	==========================================
*/
/*
	�ⷨһ��ɨ��˳���L���ؽ�Aֻ����������x��Ԫ��
*/
void delnode1(SqList * &L, int x)
{
	int i = 0;
	int k = 0;					//kֵ��¼������Ԫ�صĸ��� 
	while (i < L->length)
	{
		if (L->data[i] != x)
		{
			L->data[k] = L->data[i];
			k++;
		}
		i++;
	}
	L->length = k;
}
/*
	�ⷨ��������Ϊx��Ԫ��ǰ��k��λ�ã�����޸�L�ĳ��ȡ�
*/
void delnode2(SqList * &L, int x)
{
	int i = 0;
	int k = 0;					//kֵ��¼ɾ����Ԫ�صĸ��� 
	while (i < L->length)
	{
		if (L->data[i] == x)
		{
			k++;
		}
		else
		{
			L->data[i - k] = L->data[i];
		}
		i++;
	}
	L->length -= k;
}



/*
	���⣺
		��˳�������10������������㷨���Ե�һ��Ԫ��Ϊ�ֽ��ߣ���׼����
	������С�ڵ�������Ԫ���Ƶ���Ԫ�ص�ǰ�棬�����д�������Ԫ���Ƶ���
	Ԫ�صĺ��� ��
		----  --------------------------------------
		| x | |				������������		        |
		----  --------------------------------------
							 |
							\/
		-------- -------   ----	 ------------------
		|		<=x		| | x |	 |		>x	       |
		-------- -------   ----	 ------------------
*/
/*
	���ֽⷨmove1��move2
	����
			j�Ӻ���ǰ��<=pivot��Ԫ��
			i��ǰ�����>pivot��Ԫ��
	��ͬ��Ϊ:
			move1��Ҫ������¼a,b������temp=a;a=b;b=temp;
			move2������ڼ�¼����������
*/
void move1(SqList * &L)
{
	int i, j;
	int pivot;
	int temp;
	i = 0;
	j = L->length - 1;
	pivot = L->data[0];					//��data[0]Ϊ��׼ 
	while (i < j)
	{
		while (i<j && L->data[j]>pivot)
		{
			j--;						//�Ӻ���ǰɨ�裬�ҵ�һ��<=pivot��Ԫ�� 
		}
		while (i < j && L->data[i] <= pivot)	//��ǰ����ɨ�裬�ҵ�һ��>pivot��Ԫ�� 
		{
			i++;
		}
		if (i < j)
		{
			temp = L->data[i];			//L->data[i]��L->data[j]���� 
			L->data[i] = L->data[j];
			L->data[j] = temp;
		}
	}
	temp = L->data[i];					//L->data[0]��L->data[j]���� 
	L->data[i] = pivot;
	L->data[0] = temp;
}
//�ⷨ2 
void move2(SqList * &L)
{
	int i, j;
	int pivot;
	i = 0;
	j = L->length - 1;
	pivot = L->data[0];	//��data[0]Ϊ��׼ 
	while (i < j)
	{
		while (i<j && L->data[j]>pivot)	//�Ӻ���ǰɨ�裬�ҵ�һ��<=pivot��Ԫ�� 
		{
			j--;
		}
		L->data[i] = L->data[j];			//�������data[i]�� 
		while (i < j && L->data[i] <= pivot)	//��ǰ����ɨ�裬�ҵ�һ��>pivot��Ԫ�� 
		{
			i++;
		}
		L->data[j] = L->data[i];			//�������data[j]�� 
	}
	L->data[i] = pivot;					//���û�׼ 
}


