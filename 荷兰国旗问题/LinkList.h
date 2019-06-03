/*
	==================2019.4.13===============
	1.���嵥������ͷ��㣩�ṹ������Ԫ��int���ͣ�
	2.���嵥����Ļ������㡣
	==========================================
*/
#include<stdlib.h>
#include<stdio.h>
typedef struct LNode {	//���嵥����ڵ����� 
	int data;
	struct LNode* next;	//ָ���̽ڵ� 
}LinkList;

//1.����������
//���彨�������������ַ�����ͷ�巨��β�巨 
// ��1��ͷ�巨����front
void CreateListF(LinkList*& L, int a[], int n)
{
	LinkList* node;
	int i;
	L = (LinkList*)malloc(sizeof(LinkList));
	L->next = NULL;				//����ͷ�ڵ㣬��next����ΪNULL 
	for (i = 0; i < n; i++)			//ѭ���������ݽڵ� 
	{
		node = (LinkList*)malloc(sizeof(LinkList));
		node->data = a[i];	//�������ݽڵ�node; 
		node->next = L->next;	//��*node����ͷ�ڵ�� 
		L->next = node;
	}
}
//��2��β�巨����������rear
void CreateListR(LinkList*& L, int a[], int n)
{
	LinkList* r;
	LinkList* node;
	int i;
	L = (LinkList*)malloc(sizeof(LinkList));	//����ͷ�ڵ� 
	L->next = NULL;
	r = L;									//rʼ��ָ��β�ڵ㣬��ʼʱָ��ͷ�ڵ� 
	for (i = 0; i < n; i++)						//ѭ���������ݽڵ� 
	{
		node = (LinkList*)malloc(sizeof(LinkList));
		node->data = a[i];					//�������ݽڵ� 
		r->next = node;						//��*node����*r֮�� 
		r = node;
	}
	r->next = NULL;							//β�ڵ�next����ΪNULL�� 
}

//������Ļ�������
//��1����ʼ��������
void InitList(LinkList*& L)
{
	L = (LinkList*)malloc(sizeof(LinkList));
	L->next = NULL;
}
//(2)���ٵ�����
void DestroyList(LinkList*& L)
{
	LinkList* pre, * post;//postָ��pre�ĺ�һ���ڵ� 
	int i;
	pre = L;				//��ʼʱpreָ��ͷ�ڵ� 
	post = pre->next;
	while (post != NULL)	//ɨ�赥���� 
	{
		free(pre);		//�ͷ�ǰһ���ڵ�pre 
		pre = post;		//preָ���һ���ڵ�post 
		post = post->next;//postָ���һ���ڵ� 
	}
	free(pre);			//���postָ��null���ͷ�pre 
}
//��3)�жϵ������Ƿ�Ϊ�� 
bool ListEmpty(LinkList* L)
{
	return L->next == NULL;
}
//(4)������ĳ���
int ListLength(LinkList* L)
{
	int l = 0;
	LinkList* p = L;
	while (p->next != NULL)
	{
		l++;
		p = p->next;
	}
	return l;
}
//(5)���������
void DispLinList(LinkList* L)
{
	LinkList* p = L->next;
	while (p != NULL)
	{
		printf("%d", p->data);
		p = p->next;
	}
	printf("\n");
}
//(6)��������λ��i��Ԫ��ֵ
bool GetElem(LinkList* L, int i, int& e)
{
	LinkList* p = L;
	int j = 0;
	while (i < j && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
	{
		return false;
	}
	else
	{
		e = p->data;
		return true;
	}
}
//(7)��Ԫ��ֵ����
int LocateElem(LinkList* L, int e)
{
	LinkList* p = L->next;
	int i = 1;
	while (p != NULL)
	{
		if (p->data == e)
		{
			return i;
		}
		p = p->next;
		i++;
	}
	return 0;
}
//��8)��������Ԫ��
bool ListInsert(LinkList*& L, int i, int e)
{
	LinkList* p = L;
	LinkList* a;
	int j = 0;
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL || j != i - 1)
	{
		return false;
	}
	else
	{
		a = (LinkList*)malloc(sizeof(LinkList));
		a->data = e;
		a->next = p->next;
		p->next = a;
		return true;
	}
}
//��9��ɾ�����ݽڵ�
bool ListDelete(LinkList*& L, int i, int& e)
{
	LinkList* p = L;
	LinkList* a;
	int j = 0;
	while (j < i - 1 && p != NULL)
	{
		p = p->next;
		j++;
	}
	if (p == NULL || j != i - 1)
	{
		return false;
	}
	else
	{
		a = p->next;
		if (a == NULL)
		{
			return false;
		}
		e = a->data;
		p->next = a->next;
		free(a);
		return true;
	}
}



/*
	==============2019.4.14=================
	���⣺(�Բ���Ϊ�������㷨���)
		���һ���㷨��ɾ����������Ԫ��ֵ���
	��Ԫ�أ��������ֵΨһ��
	========================================
*/
void delmaxnode(LinkList*& L)
{
	LinkList* p = L->next, * pre = L, * maxp = p, * maxpre = pre;//p��preʱһ��ͬ��ָ�� 
	while (p != NULL)
	{
		if (p->data > maxp->data)						//�Ƚ�p��ֵ�����ֵ 
		{
			maxp = p;									//�����󣬸���maxp��maxpre 
			maxpre = pre;
		}
		p = p->next;									//p��preͬ������ 
		pre = pre->next;
	}
	maxpre->next = maxp->next;					//ɾ��maxp 
	free(maxp);									//�ͷ�maxp 
}
/*���㷨��ʱ�临�Ӷ�ΪO(n)*/

/*
	===============2019.4.16=========================
	���⣺(�Բ���Ϊ�������㷨���)
		��һ����ͷ���ĵ�����������һ�����ݽڵ㣩��
	���һ���㷨��ʹ������Ԫ�ص�����������
	=================================================
*/
void sort(LinkList*& L)
{
	LinkList* p, * pre, * post;
	p = L->next->next;			//pָ��L�ĵڶ������ݽڵ�
	L->next->next = NULL;		//����һ��ֻ��һ�����ݽڵ�������
	while (p != NULL)
	{
		post = p->next;			//post����p�ĺ�̽ڵ��ָ��
		pre = L;				//�������Ŀ�ͷ���бȽϣ�preָ�����*p��ǰ���ڵ�
		while (pre->next != NULL && p->data > pre->next->data)
		{
			pre = pre->next;	//��������в��Ҳ���*p��ǰ���ڵ�*pre
		}
		p->next = pre->next;	//����*P
		pre->next = p;
		p = post;				//*pָ����һ������������ݽڵ�
	}
}
/*���㷨��ʱ�临�Ӷ�ΪO(n^2)*/

/*
	=============2019.4.16==========================
	���⣺(�Խ���Ϊ�������㷨���)
		������һ����ͷ���ĵ�����L={a1,a2,a3,...,an}��
		���һ���㷨�����нڵ�����;
	================================================
*/
//ͷ�巨���½���
void reverse(LinkList*& L)
{
	LinkList* p, * post;
	p = L->next;		//pָ��L�ĵ�һ������Ԫ��
	L->next = NULL;		//L������Ԫ���ÿ�
	while (p != NULL)	//ͷ�巨����
	{
		post = p->next;
		p->next = L->next;
		L->next = p;
		p = post;
	}
}
/*���㷨��ʱ�临�Ӷ�ΪO(n)*/

/*
	================2019.4.21=============================
	���⣺
		������һ����ͷ���ĵ�����L={a1,b1,a2,b2,...,an,bn}��
		���һ���㷨�����ֳ�������ͷ�ڵ�ĵ�����L1��L2��
		L1={a1,a2,...,an}	L2={bn,bn-1,...,b1}
		Ҫ��L1ʹ��L��ͷ�ڵ㡣
	======================================================
*/
//L1β�巨����L2ͷ�巨����
void split(LinkList* L, LinkList*& L1, LinkList*& L2)
{
	LinkList* p = L->next;	//pָ��ԭ����ĵ�һ�����ݽڵ�
	LinkList* r1, * q;		//r1ָ��L1��β�ڵ㣬q����p�ĺ�̽ڵ�
	L1 = L;					//L1ʹ��L��ͷ�ڵ�
	r1 = L1;				
	L2 = (LinkList*)malloc(sizeof(LinkList));//ΪL2����ռ�
	L2->next = NULL;		//��L2��ָ����ΪNULL
	while (p != NULL)
	{
		r1->next = p;		//L1β�巨����
		r1 = p;
		p = p->next;
		if (p != NULL)
		{
			q = p;			//L2ͷ�巨����
			p = p->next;
			q->next = L2->next;
			L2->next = q;
		}
	}
	r1->next = NULL;		//���L1β�ڵ�next�ÿ�
}
//ʱ�临�Ӷ�ΪO(n)

