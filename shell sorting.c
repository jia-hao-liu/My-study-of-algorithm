#include<stdio.h>//需要更改与理解

void Shellsort(int arr[], int N);

int main(void)
{

    int i,N;
    puts("Please input your numbers' number:");
    scanf("%d", &N);
    int input[N];
    puts("Please input your numbers");
    for(i=0;i<N;i++)
    {
        scanf("%d", &input[i]);
    }
    Shellsort(input,N);
    for(i=0;i<N;i++)
    {
        printf("%d  ",input[i]);
    }
    return 0;
}


void Shellsort(int arr[], int N)
{
    /*int H,i,j,k,temp;
    for(H=N/2;H>0;H/=2)
    {
        for(i=0;i<H;i++)
        {
            //进行插入排序
            for(j=i;j<N;j+=H)
            {
                temp=arr[j];
                for(k=j;k>0 && arr[k-1]>temp;k--)
                {
                    arr[k]=arr[k-1];
                }
                arr[k]=temp;
            }
        }
    }*/
    int i,j,IN;
    int temp;
    for(IN=N/2;IN>0;IN/=2)
    {
        for(i=IN;i<N;i++)
        {
            temp=arr[i];
            for(j=i;j>=IN ;j-=IN)
            {


                if(temp<arr[j-IN])
                    arr[j]=arr[j-IN];
                else
                    break;
            }
            arr[j]=temp;
        }
    }



}
