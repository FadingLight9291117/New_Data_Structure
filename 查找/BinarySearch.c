/*******************************/
/*		二分查找/折半查找		*/
/******************************/
#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int *data;
	int len;
}Array;
int Binary_Search(Array* array,int key)
{
	int low = 0,high = array->len-1,mid;
	while (low <= high)
	{
		mid = (low+high)/2;
		if (array->data[mid] == key)
		{
			return mid;
		}
		else if (array->data[mid] > key)
		{
			high = mid - 1;
		}
		else if (array->data[mid] < key)
		{
			low = mid + 1;
		}
	}
	return -1;
}
int main()
{
	int a[6] = {2,5,7,9,12,16};
	Array *array = (Array*)malloc(sizeof(Array));
	array->data = a;
	array->len = 6;
	int result = Binary_Search(array,9);
	printf("%d\n",result);
	return 0;	
}
