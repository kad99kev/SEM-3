/*
 Title   : Implementation of stack using array
 Name    : Kevlyn Kadamala
 Roll no.: 8340
 */


#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

typedef struct stack    //Stack declaration
{
    int a[SIZE], top;
}stk;

void init_stack(stk *p) //Stack initialization function
{
    p->top=-1;
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
    if(isfull(p->top))
    {
      printf("Stack overflow\n");
    }
    else
    {
        p->a[++p->top]=x;
    }
}

int pop(stk *p) //To pop values out of stack
{
    int x;
    if(isempty(p->top))
    {
        printf("Stack underflow\n");
        return -1;
    }
    else
    {
        x=p->a[p->top];
        (*p).top--;
        return x;
    }
}

void delete(stk *s)
{
    int n, i;
    printf("Enter position of element to be deleted\n");
    scanf("%d", &n);
    for(i = s->top; i > n ; i--)
    {
        s->a[i - 1] = s->a[i];
    }
    s->top -= 1;
}

void display(stk *p)    //To display contents of stack
{
    int i;
    for(i=p->top; i>=0; i--)
        printf("%d\n", p->a[i]);
}



int peek(stk *p)    //To check topmost value in the stack
{
    return p->a[p->top];
} 
  
int size(stk *p)
{
    return (p->top+1);
} 




void main()
{
    int e;
    stk s;
    init_stack(&s);
    push(&s,10);
    push(&s,20);
    e=pop(&s);
    if(e!=-1)
    {
        printf("Element popped out is %d\n", e);
    }
    push(&s,30);
    push(&s,50);
    push(&s,60);
    e=pop(&s);
    if(e!=-1)
    {
        printf("Element popped out is %d\n", e);
    }
    push(&s,40);
    e=peek(&s);
    printf("Elements in stack are\n");
    display(&s);
    printf("Top value is %d\n", e);
    e=size(&s);
    printf("No. elements inside is %d\n", e);
    delete(&s);
    printf("Elements in stack are\n");
    display(&s);
}


/*
 Element popped out is 20
 Element popped out is 60
 Elements in stack are
 40
 50
 30
 10
 Top value is 40
 No. elements inside is 4
 Enter position of element to be deleted
 2
 Elements in stack are
 40
 30
 10
 */
 
