/**********/
/*  堆    */
/*********/
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
#define MAX_DATA 1000
/*大根堆*/
typedef struct Heap
{
    int data[MAX_SIZE];
    int size;
}MaxHeap;

/*插入一个元素*/
void HeapInsertion(MaxHeap *heap,int e)
{
    heap->size++;
    int parent;
    int child = heap->size;
    for (parent = heap->size / 2; parent > 0; parent = child / 2)
    {
        if (heap->data[parent] < e)
        {
            heap->data[child] = heap->data[parent];
            child = parent;
        }
        else
            break; 
    }
    heap->data[child] = e;
}

/*弹出最大值*/
int Pop(MaxHeap *&heap)
{
    int size = heap->size;
    int *data = heap->data;
    if (size == 0)
    {
        return -1;
    }
    --heap->size;
    int result = data[1];
    int temp = data[size];
    --size;
    int parent,child;
    for (parent = 1; parent*2 <= size; parent = child)
    {
        child = parent*2;
        if (child != size && data[child+1] > data[child])
            ++child;
        if (data[child] > temp)
            data[parent] = data[child];
        else
            break;
    }
    data[parent] = temp;
    return result;
}

/*根据数组参数建堆*/
void HeapCreation(MaxHeap *&heap, int *a,int n)
{   
    /*首先按顺序存入*/
    heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->data[0] = MAX_DATA;
    for (int i = 0; i < n; i++)
    {
        heap->data[i+1] = a[i];
    }
    heap->size = n;
    /*调整为大根堆*/
    for (int i=n; i>1; i -= 2) // 循环调整每一个子树
    {
        int temp = heap->data[i/2];
        int parent;
        for (parent = i/2; parent*2 <= n;) // 将一个子树调整为大根堆
        {
            int child = parent*2;
            if (child != n && heap->data[child+1] > heap->data[child])
                ++child;
            if (heap->data[child] > temp)
            {
                heap->data[parent] = heap->data[child];
                parent = child;
            }
            else
                break;
        }
        heap->data[parent] = temp;
    }
}

int main(int argc, char const *argv[])
{
    int a[8] = {1,2,4,5,32,5,87,12};
    MaxHeap *heap;
    HeapCreation(heap,a,8);
    for (int i = 1; i <= heap->size; i++)
    {
        printf("%d ",heap->data[i]);
    } 
    printf("\n");

    HeapInsertion(heap,10);
    HeapInsertion(heap,12);
    HeapInsertion(heap,100);
    HeapInsertion(heap,0);
    HeapInsertion(heap,30);


    int result;
    while (true)
    {
        result = Pop(heap);
        if (result == -1)
            break;
        printf("%d ",result);
    }
    printf("\n");

    return 0;
}
