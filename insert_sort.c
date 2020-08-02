/*
    插入排序
*/

#include <stdio.h>
/*
    插入排序函数
    params:
        *arr-待排数组指针
        len-数组长度
*/
void insert_sort(int *arr, int len)
{
    for (int i = 1; i < len; i++)
    {                      // 前i-1个元素是有序的
        int temp = arr[i]; // 摸下一张牌
        int j;
        for (j = i; j > 0 && arr[j - 1] > temp; j--)
        {
            arr[j] = arr[j - 1]; // 移出空位，空位向左移动一位
        }
        arr[j] = temp; // 放入新牌
    }
}

/*
    测试
*/
int main()
{
    int a[8] = {3, 12, 5, 2, -2, 10, -29, 4};
    insert_sort(a, 8);
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}