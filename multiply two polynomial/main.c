#include <stdio.h>
#include <stdlib.h>
struct polynomial{
    int coef;
    int expon;
    struct polynomial* next;
};
int main()
{
    struct polynomial* p1;
    struct polynomial* p2;
    struct polynomial* p;
    p1=inputpol();
    p2=inputpol();
    p=multiply(p1,p2);

    printpol(p);

    return 0;
}
