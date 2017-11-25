#include<stdio.h>
#include<stdlib.h>

int insertionsort(int arr[],int cmp[], int N);
void merge(int arr[],int temparr[],int left, int right, int rightend);
void mergesort(int arr[], int cmp[],int N);
void Msort(int arr[],int temp[],int cmp[],int* flag,int left, int right, int N);

int main(void)
{
    int i,N,flag=0;

    //puts("Please input your sorting number numbers:");
    scanf("%d", &N);

    int input1[N],input2[N],temp[N];

    //puts("Please input your numbers:");
    for(i=0;i<N;i++)
    {
        scanf("%d", &input1[i]);
        temp[i]=input1[i];
    }

    for(i=0;i<N;i++)
      scanf("%d", &input2[i]);
    flag=insertionsort(input1,input2,N);
    if(flag)
      {
        puts("Insertion Sort");
        for(i=0;i<N;i++)
        {
          if(i==0)
            printf("%d",input1[i]);
          else
            printf(" %d",input1[i]);
        }
      }
    else
    {
      puts("Merge Sort");
      mergesort(temp,input2,N);
    }

    return 0;
}





void mergesort(int arr[],int cmp[], int N)
{
    int* flag=malloc(sizeof(int));
    *flag=0;
    int temp[N];
    Msort(arr,temp,cmp,flag,0,N-1, N);
}

void Msort(int arr[],int temp[], int cmp[],int* flag,int left, int right,int N)
{
    int i;
    int mid=(left+right)/2;
    if(left<right)
    {
        Msort(arr, temp,cmp,flag,left, mid,N);
        Msort(arr,temp,cmp,flag,mid+1, right,N);
        merge(arr,temp,left, mid+1,right);
        for(i=0;i<N;i++)
          if (arr[i]!=cmp[i])
            break;

        if(!*flag)
        {
            if(i==N)
            {

                for(i=0;i<N;i++)
                {
                    if(i==0)
                        printf("%d",arr[i]);
                    else
                        printf(" %d",arr[i]);
                }
                *flag=1;
            }

        }
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


int insertionsort(int arr[],int cmp[], int N)
{
    int i,j,temp,index;
    for(i=1;i<N;i++)
    {
        temp=arr[i];
        for(j=i;j>0 && arr[j-1]>temp;j--)
        {
            arr[j]=arr[j-1];
        }
        arr[j]=temp;
        for(index=0;index<N;index++)
        {
          if(arr[index]!=cmp[index])
            break;
        }
        if(index==N)
        {

            return 1;
        }
    }
    return 0;
}
