#include<stdio.h>
#include<stdlib.h>



typedef struct Node* PtrToNode;
struct Node{
    int num;
    PtrToNode next;
};
typedef PtrToNode Position;
struct QNode{
    Position front,rear;
    int MaxSize;
};
typedef struct QNode* Queue;


Queue CreateQueue(void);
int Isfull(Queue Q);
int IsEmpty(Queue Q);
void Enqueue(Queue Q,int num);
int Dequeue(Queue Q);
typedef struct TreeNode* PtrToTreeNode;
struct TreeNode{
    int val;
    PtrToTreeNode left;
    PtrToTreeNode right;
};
void Inorder(struct TreeNode* root);
typedef PtrToTreeNode Tree;
int* inorderTraversal(struct TreeNode* root,int* returnSize);

Tree BuildTree(int num);
void Insert(Tree T, int num);

int main(void)
{

    Tree T=BuildTree(1);
    int N;
    scanf("%d",&N);
    int num;
    for(int i=0;i<N;i++)
    {
        scanf("%d", &num);
        Insert(T,num);
        printf("111\n");
    }
    int* a=malloc(sizeof(int));
    int* p=inorderTraversal(T,a);
    printf("111\n");
    for(int i=0;i<*a;i++)
        printf("%d ",p[i]);
    return 0;

}


Queue CreateQueue(void)
{
    Queue Q=malloc(sizeof(struct QNode));
    //Q->MaxSize=MaxSize;
    Q->rear=NULL;
    Q->front=NULL;
    return Q;
}

/*int Isfull(Queue Q)
{
    int count=0;
    Position temp=Q->front;
    while(temp)
    {
        count++;
        temp=temp->next;
    }
    if(count==Q->MaxSize)
        return 1;
    else
        return 0;
}*/

int IsEmpty(Queue Q)
{
    if(Q->front!=NULL)
        return 0;
    else
        return 1;
}
void Enqueue(Queue Q, int num)
{
    /*if(Isfull(Q))
    {
        printf("队列已满！\n");
        return;
    }*/
    if(IsEmpty(Q))
    {
        PtrToNode NewNode=malloc(sizeof(struct Node));
        NewNode->num=num;
        NewNode->next=NULL;
        Q->front=NewNode;
        Q->rear=NewNode;
    }
    else
    {
        PtrToNode NewNode=malloc(sizeof(struct Node));
        NewNode->num=num;
        NewNode->next=NULL;
        Q->rear->next=NewNode;
        Q->rear=NewNode;
    }
}

int Dequeue(Queue Q)
{
    Position P;
    int returnnum;
    if(IsEmpty(Q))
    {
        printf("队列已空！\n");
        return 0;
    }
    if(Q->front==Q->rear)
    {
        P=Q->front;
        returnnum=P->num;
        Q->front=Q->rear=NULL;

    }
    else
    {
        P=Q->front;
        returnnum=P->num;
        Q->front=P->next;
    }
    free(P);
    return returnnum;

}

int count=0;
struct QNode* Q;

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    Q=CreateQueue();
    Inorder(root);
    int* result=malloc(sizeof(int)*count);
    *returnSize=count;
    count=0;
    while(!IsEmpty(Q))
    {
        result[count++]=Dequeue(Q);
    }
    return result;
}
void Inorder(struct TreeNode* root)
{
    if(root)
    {
        Inorder(root->left);
        Enqueue(Q,root->val);
        count++;
        Inorder(root->right);
    }
}
