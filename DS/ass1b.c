//
//  ass1b.c
//  
//
//  Created by Kevlyn Kadamala on 06/08/18.
//

#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

typedef struct stack    //Stack declaration
{
    int a[SIZE], top;
}stk;

void init_stack(stk *p) //Stack initialization function
{
    (*p).top=-1;
}

int isfull(int p)   //To check if stack is full
{
    if(p==SIZE-1)
        return 1;
    else
        return 0;
}

int isempty(int p) //To check if stack is empty
{
    if(p==-1)
        return 1;
    else
        return 0;
}

void push(stk *p, int x)    //To push values into stack
{
    if(isfull((*p).top))
    {
        printf("Stack overflow\n");
    }
    else
    {
        (*p).a[++(*p).top]=x;
    }
}

int pop(stk *p) //To pop values out of stack
{
    int x;
    if(isempty((*p).top))
    {
        printf("Stack underflow\n");
        return -1;
    }
    else
    {
        x=(*p).a[(*p).top];
        (*p).top--;
        return x;
    }
}

void display(stk *p)    //To display contents of stack
{
    int i;
    for(i=(*p).top; i>=0; i--)
        printf("%d ", (*p).a[i]);
    printf("\n");
}



int peek(stk *p)    //To check topmost value in the stack
{
    return (*p).a[(*p).top];
}

int size(stk *p)
{
    return ((*p).top+1);
}

void sort(stk *p)
{
    int temp=0;
    for(int i=p->top; i>0; i--)
    {
        for(int j=p->top; j>0; j--)
        {
            if(p->a[j]>p->a[j-1])
            {
                temp=p->a[j];
                p->a[j]=p->a[j-1];
                p->a[j-1]=temp;
            }
        }
    }
}



void main()
{
    int x;
    int n;
    stk s;
    init_stack(&s);
    printf("Enter number of elements to be entered\n");
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        printf("Enter element to be pushed\n");
        scanf("%d", &x);
        push(&s, x);
    }
    printf("Before sorting\n");
    display(&s);
    printf("After sorting\n");
    sort(&s);
    display(&s);
    
}

/*
 Enter number of elements to be entered
 7
 Enter element to be pushed
 8
 Enter element to be pushed
 5
 Enter element to be pushed
 7
 Enter element to be pushed
 1
 Enter element to be pushed
 9
 Enter element to be pushed
 12
 Enter element to be pushed
 10
 Before sorting
 10 12 9 1 7 5 8
 After sorting
 1 5 7 8 9 10 12
 */
