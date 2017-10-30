#include<stdio.h>
#define LeftChild(i) (2*i+1)

void Percdown(int arr[], int i, int N);
void swap(int* a, int* b);
void HeapSort(int arr[], int N);

int main(void)
{
    int i,N;
    puts("Please input your numbers' number:");
    scanf("%d", &N);
    int input[N];

    for(i=0;i<N;i++)
    {
        input[i]=rand();
    }

    HeapSort(input, N);

    for(i=0;i<N;i++)
    {
        printf("%d  ", input[i]);
    }

    //swap(&a,&b);
    return 0;
}

void Percdown(int arr[], int i, int N)
{

    int child,temp;

    temp=arr[i];
    for(;LeftChild(i)<=N-1;i=child)
    {
        child=LeftChild(i);
        if(child!=N-1 && arr[child]<arr[child+1])
            child++;
        if(arr[child]>temp)
            arr[i]=arr[child];
        else
            break;
    }
    arr[i]=temp;
}
void swap(int* a, int* b)
{
    int temp;

    temp=*a;
    *a=*b;
    *b=temp;
}

void HeapSort(int arr[], int N)
{
    int i;

    for(i=N/2-1;i>=0;i--)
        Percdown(arr, i, N);
    for(i=N-1;i>0;i--)
    {
        swap(arr,(arr+i));
        Percdown(arr, 0, --N);
    }
}


