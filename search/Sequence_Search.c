/***********************************/
/*			一般顺序表的顺序查找			*/
/*********************************/
#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int *data;
	int len;
}Array;
int Search_Seq(Array *array,int key)
{
	array->data[0] = key; // 0号元素是“哨兵”，简化操作
	int i;
	for (i=array->len;array->data[i] != key;--i);
	return i;
}
int main()
{
	Array *array = (Array*)malloc(sizeof(Array));
	int a[6] = {-1,3,2,5,12,9};
	array->data = a;
	array->len = 5;
	int result = Search_Seq(array,3);
	printf("%d\n",result);
	return 0;
}

