/*
	��ջ
*/
#include<stdio.h>
#include<stdlib.h>
//��ջ�Ķ���
typedef struct linknode
{
	char data;
	struct linknode* next;
}LiStack;

//��ʼ��ջ
void InitStack(LiStack*& s)
{
	s = (LiStack*)malloc(sizeof(LiStack));
	s->next = NULL;
}
void DestroyStack(LiStack*& s)
{
	LiStack* p = s, * q = s->next;
	if (q != NULL)
	{
		free(p);
		p = q;
		q = q->next;
	}
	free(p);
}
//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(LiStack* s)
{
	return s->next == NULL;
}
//��ջ
void Push(LiStack*& s, char e)
{
	LiStack* p = (LiStack*)malloc(sizeof(LiStack));
	p->data = e;
	p->next = s->next;
	s->next = p;
}
//��ջ
bool Pop(LiStack*& s, int& e)
{
	LiStack* p = s->next;
	s->next = p->next;
	e = p->data;
	free(p);
	return true;
}
//ȡջ��Ԫ��
bool GetTop(LiStack* s, int& e)
{
	if (StackEmpty(s))
	{
		return false;
	}
	e = s->next->data;
	return true;
}
