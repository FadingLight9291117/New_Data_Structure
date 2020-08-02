#include<stdio.h>
#include"循环双链表.h"
void testCreateDLinkListF()
{
	int a[4] = { 2,6,3,9 };
	DLinkList* L;
	CreateDLinkListF(L, a, 4);
	DispDLinkList(L);
}
void testCreateDLinkListR()
{
	int a[4] = { 2,6,3,9 };
	DLinkList* L;
	CreateDLinkListR(L, a, 4);
	DispDLinkList(L);
}
void testEqual()
{
	int a[] = { 2,2 };
	DLinkList* L;
	CreateDLinkListR(L, a, 2);
	printf("%d",Equal(L));
}
int main()
{
	//testCreateDLinkListF();
	//testCreateDLinkListR();
	testEqual();
}