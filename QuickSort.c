#include<stdio.h>                         //用书上的方法为何不行？
#include<stdlib.h>

void insertionsort(int arr[], int N);
void Swap(int* a,int* b);
int Median(int arr[],int left, int right);
void Qsort(int arr[],int left,int right);
void QuickSort(int arr[], int N);

int main(void)
{
    int N;
    scanf("%d",&N);
    int arr[N];


    for(int i=0;i<N;i++)
    {
        scanf("%d",&arr[i]);
    }
    QuickSort(arr,N);
    for(int i=0;i<N;i++)
    {
        printf("%d ", arr[i]);
    }



    return 0;
}

void Swap(int* a,int * b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int Median(int arr[],int left, int right)
{
    int temp;
    int mid=(left+right)/2;
    if(arr[left]>arr[mid])
        Swap(&arr[left],&arr[mid]);
    if(arr[left]>arr[right])
        Swap(&arr[left],&arr[right]);
    if(arr[right]<arr[mid])
        Swap(&arr[right],&arr[mid]);
    Swap(&arr[mid],&arr[right-1]);
    return arr[right-1];
}
void Qsort(int arr[],int left,int right)
{
   /* if(left<right)
    {
        int pivot=Median(arr,left,right);
        int Left,Right;


        Left=left;
        Right=right-1;
        for(;;)
        {
            while(arr[++Left]<pivot);
            while(arr[--Right]>pivot);
            if(Left<Right)
                Swap(&arr[Left],&arr[Right]);
            else
                break;
        }

        Swap(&arr[Left],&arr[right-1]);
        Qsort(arr,left,Left-1);
        Qsort(arr,Left+1,right);

    }*/
    if(left<right)
    {
        int i=left;
        int j=right;
        int x=arr[i];
        while(i<j)
        {
            while(i<j && arr[j]>x)
                j--;
            if(i<j)
                arr[i++]=arr[j];
            while(i<j && arr[i]<x)
                i++;
            if(i<j)
                arr[j--]=arr[i];
        }
        arr[i]=x;
        Qsort(arr,left,i-1);
        Qsort(arr,i+1,right);
    }

}

void QuickSort(int arr[],int N)
{
    Qsort(arr,0,N-1);
}
void insertionsort(int arr[], int N)
{
    int i,j,temp;
    for(i=1;i<N;i++)
    {
        temp=arr[i];
        for(j=i;j>0 && arr[j-1]>temp;j--)
        {
            arr[j]=arr[j-1];
        }
        arr[j]=temp;

    }
}
