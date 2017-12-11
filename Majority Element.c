#include<stdio.h>
#include<stdlib.h>


int majorityElement(int* nums, int numsSize) ;

int main(void)
{
    int N;
    scanf("%d",&N);
    int arr[N];
    for(int i=0;i<N;i++)
        scanf("%d",&arr[i]);
    printf("%d\n",majorityElement(arr,N));
    return 0;

}



int majorityElement(int* nums, int numsSize) {
    int count=0,result;
    for(int i=0;i<numsSize;i++)
    {
        if(count==0 || nums[i]==result)
        {
            result=nums[i];
            count++;
        }
        else
            count--;
    }
    return result;
}
