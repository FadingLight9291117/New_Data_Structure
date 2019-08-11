/***************/
/*  冒泡排序    */
/**************/
#include<stdio.h>
void Bubble_Sort(int *a,int n)
{
    for (int i = n - 1; i >= 0; i--)    // 一趟冒泡
    {
        int flag = 0;
        for (int j = 0; j < i; j++)
        {
            if (a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = 1;               // 发生了交换
            }
        }
        if (flag == 0)                  // 全程无交换 
            break;        
    }
}

int main(int argc, char const *argv[])
{
    int a[8] = {2,4,1,12,9,5,6,10};
    Bubble_Sort(a,8);
    for (int i = 0; i < 8; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
