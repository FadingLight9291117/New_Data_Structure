#include<stdio.h>
#include"DLinkList.h"
//测试建表
void testCreateList()
{
	//测试建表
	DLinkList* L1;
	DLinkList* L2;
	int a[4] = { 2,4,5,2, };
	CreateDLinkListF(L1, a, 4);
	CreateDLinkListR(L2, a, 4);
	DispList(L1);
	DispList(L2);
}
//测试插入
void testInsert()
{
	DLinkList* L;
	int a[4] = { 2,4,5,2 };
	CreateDLinkListR(L, a, 4);
	DispList(L);
	ListInsert(L, 5, 3);
	DispList(L);
}
//测试删除
void testDelete()
{
	DLinkList* L;
	int a[4] = { 2,5,2,1 };
	CreateDLinkListR(L, a, 4);
	DispList(L);
	int e=-1;
	ListDelete(L, 5, e);
	DispList(L);
	printf("%d", e);
}
void testReverse()
{
	DLinkList* L;
	int a[7] = { 2,5,2,1,3,5,9 };
	CreateDLinkListR(L, a, 7);
	DispList(L);
	Reverse(L);
	DispList(L);
}
int main()
{
	//testCreateList();
	//testInsert();
	//testDelete();
	testReverse();
}