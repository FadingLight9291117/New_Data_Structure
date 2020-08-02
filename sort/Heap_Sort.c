/**************/
/*  堆排序    */
/************/
#include<stdio.h>
/*下滤：将n个节点的数组a，以a[p]为根节点调整为大根堆*/
void PercDown(int *a,int p, int n)
{
    int parent,child;
    int temp = a[p];                                    // 取出根节点存放的值
    for (parent = p; parent*2 + 1 <= n - 1; parent = child)
    {
        child = parent*2 + 1;
        if (child != n-1 && a[child+1] > a[child])
            ++child;                                    // 将child指向左右孩子中最大的一个
        if (a[child] > temp)                            // 下滤
            a[parent] = a[child];
        else                                            // 找到了合适的位置
            break;
    }
    a[parent] = temp; 
}
/*堆排序*/
void Heap_Sort(int *a, int n)
{
    /*建立最大堆*/
    for (int i = n/2; i >= 0; --i)
    {
        PercDown(a,i,n);
    }
    /*调整为升序数组*/
    for (int i = n-1; i >=0; --i)
    {
        /*删除最大值*/
        int temp = a[0];    // 堆顶和最后一个元素交换
        a[0] = a[i];
        a[i] = temp;

        PercDown(a,0,i);    // 下滤
    }
}
/*测试*/
int main()
{
    int a[10] = {12,3,5,12,56,23,12,54,90,2};
    Heap_Sort(a,10);
    for (int i = 0; i<10; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");

}