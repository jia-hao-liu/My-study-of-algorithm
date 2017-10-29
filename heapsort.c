#include<stdio.h>
#define LeftChild(i) (2*i+1)

struct HeapStruct{
    int Capacity;
    int Size;
    int *HeapElements;
};
typedef struct HeapStruct* Heap;
Heap makeheap(int MaxElements);
int IsFull(Heap H);
void HeapInsert(Heap H, int M);
void HeapSort(int arr[],int N);
int  DeleteMin(Heap H);


int main(void)
{

   int N=0,i;
   puts("Please input  numbers:");
   scanf("%d", &N);
   int input[N];
   //puts("Please input your numbers.");
   for(i=0;i<N;i++)
   {
       input[i]=rand();
   }
    HeapSort(input,N);
    for(i=0;i<N;i++)
    {
        printf("%d  ", input[i]);
    }
    return 0;
}


Heap makeheap(int MaxElements)
{
    Heap H;
    H=malloc(sizeof(struct HeapStruct));
    H->HeapElements=malloc((MaxElements+1)*sizeof(int));
    H->Capacity=MaxElements;
    H->Size=0;
    H->HeapElements[0]=0;
    return H;
}


int IsFull(Heap H)
{
    if(H->Capacity==H->Size)
        return 1;
    else
        return 0;
}


void HeapInsert(Heap H, int M)
{
    int i;
    if(IsFull(H))
        puts("The Heap is full.");
    for(i=++H->Size;i>1 && M<H->HeapElements[i/2];i/=2)
    {
        H->HeapElements[i]=H->HeapElements[i/2];
    }
    H->HeapElements[i]=M;
}


int DeleteMin(Heap H)
{
    int min,LastElement,i,child;
    //先检查是否为空堆，这里假设不是空堆
    min=H->HeapElements[1];
    LastElement=H->HeapElements[H->Size--];
    for(i=1;i*2<=H->Size;i=child)
    {
        child=2*i;
        if(child!=H->Size && H->HeapElements[child]>H->HeapElements[child+1])
            child++;
        if(LastElement>H->HeapElements[child])
            H->HeapElements[i]=H->HeapElements[child];
        else
            break;
    }
    H->HeapElements[i]=LastElement;
    return min;
}


void HeapSort(int arr[], int N)
{
    int i,heaparr[N];
    Heap H;
    H=makeheap(100);
    for(i=0;i<N;i++)
    {
        HeapInsert(H,arr[i]);
    }
    for(i=0;i<N;i++)
    {
        arr[i]=DeleteMin(H);
    }

}
