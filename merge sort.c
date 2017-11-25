#include<stdio.h>                  //分为递归和非递归版本
#define MaxSize 100

void Msort_nonrecursion(int arr[],int temparr[],int N,int length);
void mergesort_nonrecur(int arr[],int N);
void merge(int arr[],int temparr[],int left, int right, int rightend);
void mergesort(int arr[], int N);
void Msort(int arr[],int temp[],int left, int right);


int main(void)
{
    int number[MaxSize],N,i=0;
    puts("Please input your numbers' number:");
    scanf("%d", &N);
    puts("Please input your numbers:");
    for(i=0;i<N;i++)
        scanf("%d", &number[i]);
    mergesort_nonrecur(number,N);
    for(i=0;i<N;i++)
        printf("%d ",number[i]);

    return 0;
}

void Msort_nonrecursion(int arr[],int temparr[],int N,int length)
{
    int i;
    for(i=0;i<=N-2*length;i+=2*length)
    {
        merge(arr,temparr,i,i+length,i+2*length-1);
    }
    if(i+length<N)
        merge(arr,temparr,i,i+length,N-1);
    else                                            //这一步是否多余？No
    {
        for(int j=i;j<N;j++)
            temparr[j]=arr[j];
    }
}

void mergesort_nonrecur(int arr[],int N)
{
    int length=1;
    int temp[N];
    while(length<N)
    {
        Msort_nonrecursion(arr,temp,N,length);
        length*=2;
        Msort_nonrecursion(temp,arr,N,length);
        length*=2;
    }
}


void mergesort(int arr[], int N)
{
    int temp[N];
    Msort(arr,temp,0,N-1);
}

void Msort(int arr[],int temp[], int left, int right)
{
    int mid=(left+right)/2;
    if(left<right)
    {
        Msort(arr, temp,left, mid);
        Msort(arr,temp,mid+1, right);
        merge(arr,temp,left, mid+1,right);
    }
}




void merge(int arr[],int temparr[], int left, int right, int rightend)
{   int i;
    int elementnum=rightend-left+1;
    int L=left;
    int tmppos=left;
    int leftend=right-1;

    while(left<=leftend && right<=rightend)
    {
        if(arr[left]<arr[right])
            temparr[tmppos++]=arr[left++];
        else
            temparr[tmppos++]=arr[right++];
    }
    while(left<=leftend)
        temparr[tmppos++]=arr[left++];
    while(right<=rightend)
        temparr[tmppos++]=arr[right++];


    for(i=0;i<elementnum;i++, rightend--)
        arr[rightend]=temparr[rightend];

}

