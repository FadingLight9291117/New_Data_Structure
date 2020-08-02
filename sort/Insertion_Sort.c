/***************/
/*  插入排序    */
/**************/
#include<stdio.h>
void Insertion_Sort(int *a,int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = a[i];                        // 摸下一张牌
        int j;
        for (j = i; j>0 && a[j-1] > temp; j--)
        {
            a[j] =  a[j-1];                     // 移出空位，往后移一位
        }
        a[j] = temp;                            // 放入新牌 
    }
}
/* 测试*/
int main(int argc, char const *argv[])
{
    int a[8] = {2,4,1,12,9,5,6,10};
    Insertion_Sort(a,8);
    for (int i = 0; i < 8; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
