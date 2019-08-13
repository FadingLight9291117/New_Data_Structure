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
    int *data;
    int size;
}MaxHeap;

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
    for (int i = n; i > 0; i--)
    {
        
    }
    
}