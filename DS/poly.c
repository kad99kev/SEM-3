/*
 Title   : Static Implementation of Linear queue
 Name    : Kevlyn Kadamala
 Roll no.: 8340
 */

#include <stdio.h>
#include<stdlib.h>

typedef struct node //Node Declaration
{
    int coeff, power;
    struct node *next;
}nd;

nd *START1=NULL;
nd *START2=NULL;
nd *START3=NULL;
nd *START4=NULL;

nd *end(nd *p, int pow, int cof, nd *START) //To insert node at the end
{
    p=(nd *)malloc(sizeof(nd));
    nd *ptr;
    p->power=pow;
    p->coeff=cof;
    if(START==NULL)
    {
        START=p;
        p->next=NULL;
    }
    else
    {
        ptr=START;
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=p;
        p->next=NULL;
    }
    return START;
}

nd *read(nd *node, nd *START) //To read information about polynomial
{
    node=(nd *)malloc(sizeof(nd));
    int check=1, pow, cof;
    printf("Enter coefficient in decreasing order of power\nEnter power -1 to stop\n");
    while(1)
    {
        printf("Enter power: ");
        scanf("%d", &pow);
        check=pow;
        if(check==-1)
            break;
        printf("Enter coefficient: ");
        scanf("%d", &cof);
        START=end(node,pow,cof,START);

    }
    return START;
}

nd *add(nd *ptr3) //To add two polynomials
{
    nd *ptr1, *ptr2;
    ptr1=START1;
    ptr2=START2;
    int pow,cof;
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->power==ptr2->power)
        {
            cof=ptr1->coeff+ptr2->coeff;
            pow=ptr1->power;
            START3=end(ptr3,pow,cof,START3);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        else if(ptr1->power<ptr2->power)
        {
            pow=ptr2->power;
            cof=ptr2->coeff;
            START3=end(ptr3,pow,cof,START3);
            ptr2=ptr2->next;
        }
        else
        {
            pow=ptr1->power;
            cof=ptr1->coeff;
            START3=end(ptr3,pow,cof,START3);
            ptr1=ptr1->next;
        }
        
    }
    if(ptr1==NULL && ptr2!=NULL)
    {
       while(ptr2!=NULL)
       {
           pow=ptr2->power;
           cof=ptr2->coeff;
           ptr2=ptr2->next;
           START3=end(ptr3,pow,cof,START3);
       }
    }
    else
    {
        while(ptr1!=NULL)
        {
            pow=ptr1->power;
            cof=ptr1->coeff;
            ptr1=ptr1->next;
            START3=end(ptr3,pow,cof,START3);
        }
    }
    return START3;
}

nd *subtract(nd *ptr3) //To subtract two polynomials
{
    nd *ptr1, *ptr2;
    ptr1=START1;
    ptr2=START2;
    int pow,cof;
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->power==ptr2->power)
        {
            cof=ptr1->coeff-ptr2->coeff;
            pow=ptr1->power;
            START4=end(ptr3,pow,cof,START4);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        else if(ptr1->power<ptr2->power)
        {
            pow=ptr2->power;
            cof=0-ptr2->coeff;
            START4=end(ptr3,pow,cof,START4);
            ptr2=ptr2->next;
        }
        else
        {
            pow=ptr1->power;
            cof=ptr1->coeff;
            START4=end(ptr3,pow,cof,START4);
            ptr1=ptr1->next;
        }
    }
    if(ptr1==NULL && ptr2!=NULL)
    {
        while(ptr2!=NULL)
        {
            pow=ptr2->power;
            cof=0-ptr2->coeff;
            ptr2=ptr2->next;
            START4=end(ptr3,pow,cof,START4);
        }
    }
    else
    {
        while(ptr1!=NULL)
        {
            pow=ptr1->power;
            cof=ptr1->coeff;
            ptr1=ptr1->next;
            START4=end(ptr3,pow,cof,START4);
        }
    }
    return START4;
}

void display(nd *START) //To display list
{
    nd *ptr;
    ptr=START;
    if(START==NULL)
        printf("List is empty\n");
    else
    {
        while(ptr!=NULL)
        {
            if(ptr->coeff!=0)
            {
                if(ptr->coeff>0)
                    printf("+%dx^%d ",ptr->coeff, ptr->power);
                else
                    printf("%dx^%d ",ptr->coeff, ptr->power);
            }
            ptr=ptr->next;
        }
        printf("\n");
    }
}

void main()
{
    int i, power, coeff;
    nd a,b,c,d;
    printf("Enter first equation\n");
    START1=read(&a,START1);
    printf("First equation is\n");
    display(START1);
    printf("Enter second equation\n");
    START2=read(&b,START2);
    printf("Second equation is\n");
    display(START2);
    printf("After addition\n");
    START3=add(&c);
    display(START3);
    printf("After subtraction\n");
    START4=subtract(&d);
    display(START4);
}

/*
 Enter first equation
 Enter coefficient in decreasing order of power
 Enter power -1 to stop
 Enter power: 5
 Enter coefficient: 6
 Enter power: 3
 Enter coefficient: 4
 Enter power: 2
 Enter coefficient: 2
 Enter power: 1
 Enter coefficient: -3
 Enter power: 0
 Enter coefficient: 3
 Enter power: -1
 First equation is
 +6x^5 +4x^3 +2x^2 -3x^1 +3x^0
 Enter second equation
 Enter coefficient in decreasing order of power
 Enter power -1 to stop
 Enter power: 4
 Enter coefficient: 5
 Enter power: 3
 Enter coefficient: -3
 Enter power: 2
 Enter coefficient: 2
 Enter power: 0
 Enter coefficient: -1
 Enter power: -1
 Second equation is
 +5x^4 -3x^3 +2x^2 -1x^0
 After addition
 +6x^5 +5x^4 +1x^3 +4x^2 -3x^1 +2x^0
 After subtraction
 +6x^5 -5x^4 +7x^3 -3x^1 +4x^0
 */
