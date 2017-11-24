#include<stdio.h>
#define Null -1
#define MaxSize 100

struct tree{
    int num;
    int left;
    int right;
};

typedef struct tree* TreeNode;

int  BuildTree(struct tree T[]);
int ifiso(int T1,int T2, struct tree arr1[], struct tree arr2[]);


int main(void)
{
    struct tree Tree1[MaxSize], Tree2[MaxSize];
    TreeNode T1,T2;
    T1=BuildTree(Tree1);
    T2=BuildTree(Tree2);
    if(ifiso(T1,T2,Tree1,Tree2 ))
        printf("yes!\n");
    else
        printf("no!\n");
    return 0;
}

int BuildTree(struct tree T[])
{
    int N,i=0;

    puts("Please input the number of your data:");
    scanf("%d", &N);
    int temp[MaxSize]={0};
    if(N)
    {

        for(i=0;i<N;i++)
        {
            scanf("%d %d %d", &T[i].num, &T[i].left, &T[i].right);
            if(T[i].left!=-1)
                temp[T[i].left]=1;
            if(T[i].right!=-1)
                temp[T[i].right]=1;

        }

    }
    else
        return Null;
    for(i=0;i<N;i++)
    {
        if(temp[i]==0)
            break;
    }

    return i;

}


int ifiso(int T1, int T2, struct tree arr1[], struct tree arr2[])
{
    if(T1==Null && T2==Null)
        return 1;
    else if(T1==Null || T2==Null)
        return 0;
    else if(arr1[T1].num!=arr2[T2].num)
        return 0;
    else if(arr1[T1].left==Null && arr2[T2].left==Null)
        return ifiso(arr1[T1].right,arr2[T2].right,arr1,arr2);
    else if(arr1[T1].right==Null && arr2[T2].right==Null)
        return ifiso(arr1[T1].left,arr2[T2].right,arr1,arr2);
    else if(arr1[T1].left==Null && arr2[T2].right==Null)
        return ifiso(arr1[T1].right,  arr2[T2].left,arr1,arr2);
    else if(arr1[T1].right==Null && arr2[T2].left==Null)
        return ifiso(arr1[T1].left , arr2[T2].right,arr1,arr2);
    else if(arr1[T1].left==Null || arr1[T1].right==Null || arr2[T2].left==Null || arr2[T2].right==Null)
        return 0;
    else if(arr1[arr1[T1].left].num==arr2[arr2[T2].left].num && arr1[arr1[T1].right].num!=arr2[arr2[T2].right].num  )
        return (ifiso(arr1[T1].left,arr2[T2].left,arr1,arr2) && ifiso(arr1[T1].right,arr2[T2].right,arr1,arr2));
    else if(arr1[arr1[T1].right].num!=arr2[arr2[T2].left].num && arr1[arr1[T1].left].num!=arr2[arr2[T2].right].num  )
        return (ifiso(arr1[T1].right,arr2[T2].left,arr1,arr2) && ifiso(arr1[T1].left,arr2[T2].right,arr1,arr2));
    else
        return 0;


}
