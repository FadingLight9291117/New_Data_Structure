/*
	ѭ������������
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct LNode
{
	int data;
	struct LNode* next;
}LinkList;

//ͷ�巨����ѭ��������
void CreateLinkListF(LinkList*& L, int a[], int length)
{
	L = (LinkList*)malloc(sizeof(LinkList));
	L->next = L;
	LinkList* p;
	for (int i = 0; i < length; i++)
	{
		p = (LinkList*)malloc(sizeof(LinkList));
		p->data = a[i];
		p->next = L->next;
		L->next = p;
	}
}
//β�巨����
void CreateLinkListR(LinkList*& L, int a[], int length)
{
	LinkList* p, * r;
	L = (LinkList*)malloc(sizeof(LinkList));
	r = L;
	L->next = NULL;
	for (int i = 0; i < length; i++)
	{
		p = (LinkList*)malloc(sizeof(LinkList));
		p->data = a[i];
		r->next = p;
		r = p;
	}
	r->next = L;
}
//���������
void DispLinkList(LinkList* L) {
	LinkList* p = L->next;
	while (p != L)
	{
		printf("%d", p->data);
		p = p->next;
	}
	printf("\n");
}