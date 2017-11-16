#include<stdio.h>
#define MaxSize 100

void merge(int arr[], int left, int right, int rightend);
void mergesort(int arr[], int N);
void Msort(int arr[], int left, int right);


int main(void)
{
    int number[MaxSize],N,i=0;
    puts("Please input your numbers' number:");
    scanf("%d", &N);
    puts("Please input your numbers:");
    for(i=0;i<N;i++)
        scanf("%d", &number[i]);
    mergesort(number,N);
    for(i=0;i<N;i++)
        printf("%d ",number[i]);

    return 0;
}




void mergesort(int arr[], int N)
{
    Msort(arr,0,N-1);
}

void Msort(int arr[], int left, int right)
{
    int mid=(left+right)/2;
    if(left<right)
    {
        Msort(arr, left, mid);
        Msort(arr,mid+1, right);
        merge(arr,left, mid+1,right);
    }
}




void merge(int arr[], int left, int right, int rightend)
{   int i;
    int elementnum=rightend-left+1;
    int L=left;
    int temparr[rightend];
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
