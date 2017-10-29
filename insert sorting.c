#include<stdio.h>
//插入排序,在逆序数较小的情况下性能很好

void insertionsort(int arr[], int N);


int main(void)
{
    int i,N;

    puts("Please input your sorting number numbers:");
    scanf("%d", &N);

    int input[N];

    puts("Please input your numbers:");
    for(i=0;i<N;i++)
    {
        scanf("%d", &input[i]);
    }
    insertionsort(input,N);
    for(i=0;i<N;i++)
    {
        printf("%d  ", input[i]);
    }
    return 0;
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
