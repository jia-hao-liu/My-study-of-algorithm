#include<stdio.h>

struct polynomial{
    int coef;
    int expon;
    struct polynomial* next;
};

struct polynomial* inputpol(void){
    int c,e,N;
    scanf("%d", &N);
    struct polynomial* P1;
    struct polynomial* temp1;
    P1=malloc(sizeof(struct polynomial));
    temp1=P1;
    while(N--)
    {
        scanf("%d %d", &c, &e);
        P1->next=malloc(sizeof(struct polynomial));
        P1->next->expon=e;
        P1->next->coef=c;

        if(N==0)
        {
            P1->next->next=NULL;
            P1=temp1;
        }
        else
            P1=P1->next;
    }


    return P1;
}

void printpol(struct polynomial* p)
{
    struct polynomial* temp;
    temp=p;
    while(temp->next)
    {
        printf("%d %d ", temp->next->coef, temp->next->expon);
        temp=temp->next;
    }
}

struct polynomial* sub_multiply(struct polynomial* pol1, struct polynomial* pol2)
{
    struct polynomial* pol;
    struct polynomial* temp;
    struct polynomial* temp2;
    pol=malloc(sizeof(struct polynomial));
    temp=pol;
    temp2=pol2;
    while(temp2->next)
    {

        temp->next=malloc(sizeof(struct polynomial));
        temp->next->coef=pol1->next->coef*temp2->next->coef;
        temp->next->expon=pol1->next->expon+temp2->next->expon;
        temp=temp->next;
        temp2=temp2->next;
    }
    temp->next=NULL;
    return pol;
}










struct polynomial* plus(struct polynomial* pol1, struct polynomial* pol2)
{
        //if(!(pol1 && pol2 && pol1->next && pol2->next))
            //return null;

        struct polynomial* temp1;
        struct polynomial* temp2;
        temp1=pol1;
        temp2=pol2;



        while(temp1->next && temp2->next)
        {

            if(temp1->next->expon==temp2->next->expon)
            {
                temp1->next->coef+=temp2->next->coef;
                printf("%d\n", temp1->next->coef);
                temp1=temp1->next;
                temp2=temp2->next;

            }
            else if(temp1->next->expon>temp2->next->expon)
                temp1=temp1->next;
            else if(temp1->next->expon<temp2->next->expon)
            {
                temp2=temp2->next;
                struct polynomial* temp;
                temp=malloc(sizeof(struct polynomial));
                temp->coef=temp2->coef;
                temp->expon=temp2->expon;
                temp->next=temp1->next;
                temp1->next=temp;


            }

        }

        while(temp2->next)
        {
            temp1->next=temp2->next;

        }

        return pol1;
}

struct polynomial* multiply(struct polynomial* p1, struct polynomial* p2)
{
        struct polynomial* p;
        p=(struct polynomial*)malloc(sizeof(struct polynomial));
        p->next=NULL;
        struct polynomial* temp;
        temp=p;
        struct polynomial* temp1;
        temp1=p1;

        while(temp1->next)
        {
            p=plus(sub_multiply(temp1,p2),p);
            temp1=temp1->next;
        }
        return p;
}
