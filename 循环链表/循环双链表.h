/*
	ѭ��˫����
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct DLNode
{
	int data;
	struct DLNode* next;
	struct DLNode* prior;
}DLinkList;
//ͷ�巨����
void CreateDLinkListF(DLinkList*& L, int a[], int length)
{
	L = (DLinkList*)malloc(sizeof(DLinkList));
	L->next = L;
	L->prior = L;
	DLinkList* p;
	for (int i = 0; i < length; i++)
	{
		p = (DLinkList*)malloc(sizeof(DLinkList));
		p->data = a[i];
		p->next = L->next;
		L->next->prior = p;
		L->next = p;
		p->prior = L;
	}
}
//β�巨����
void CreateDLinkListR(DLinkList*& L, int a[], int length)
{
	L = (DLinkList*)malloc(sizeof(DLinkList));
	L->next = L;
	L->prior = L;
	DLinkList* p;
	for (int i = 0; i < length; i++)
	{
		p = (DLinkList*)malloc(sizeof(DLinkList));
		p->data = a[i];
		p->prior = L->prior;
		L->prior->next = p;
		p->next = L;
		L->prior = p;
	}
}
//�������
void DispDLinkList(DLinkList* L)
{
	DLinkList* p = L->next;
	while(p->next != L)
	{
		printf("%d", p->data);
		p = p->next;	
	}
	printf("\n");
}