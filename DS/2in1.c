 /*
 Title   : Implementation of two stacks in array
 Name    : Kevlyn Kadamala
 Roll no.: 8340
 */

#include<stdio.h>
#include<stdlib.h>
#define SIZE 20
struct stack    //Stack declaration
{
    int a[SIZE], top1, top2;
};

void init_stack(struct stack *p)    //Stack initialization function
{
    p->top1=-1;
    p->top2=20;
}

void push1(struct stack *p, int x)  //To push values into stack 1
{
    if(p->top1+1 == p->top2)
        printf("Stack 1 overflow\n");
    else
        p->a[++p->top1]=x;
}

void push2(struct stack *p, int x) //To push values into stack 2
{
    if(p->top2-1 == p->top1)
        printf("Stack 2 overflow\n");
    else
        p->a[--p->top2]=x;
}

int pop1(struct stack *p)   //To pop values out of stack 1
{
    int x;
    if(p->top1==-1)
        printf("Stack underflow\n");
    else
        x=p->a[p->top1];
    --p->top1;
    return x;
}

int pop2(struct stack *p)   //To pop values out of stack 2
{
    int x;
    if(p->top2==SIZE)
        printf("Stack underflow\n");
    else
        x=p->a[(*p).top2];
    ++p->top2;
    return x;
}

void display1(struct stack *p)  //To display contents of stack 1
{
    int i;
    for(i=p->top1; i>=0; i--)
        printf("%d\n", p->a[i]);
}

void display2(struct stack *p)  //To display contents of stack 2
{
    int i;
    for(i=p->top2; i<SIZE; i++)
        printf("%d\n", p->a[i]);
}


void main()
{
    int x, i, n1,n2;
     struct stack s;
     init_stack(&s);
     printf("Enter number elements for stack 1\n");
     scanf("%d", &n1);
     for(i=1; i<=n1; i++)
     {
         printf("Enter value\n");
         scanf("%d", &x);\
         push1(&s,x);
     }
     printf("Enter number elements for stack 2\n");
     scanf("%d", &n2);
     for(i=1; i<=n2; i++)
    {
         printf("Enter value\n");
         scanf("%d", &x);\
         push2(&s,x);
    }

    printf("Enter number elements to be popped in stack 1\n");
     scanf("%d", &n1);
     for(i=1; i<=n1; i++)
     {
            x=pop1(&s);
            printf("Element popped out of 1st stack is %d\n", x);
     }

    printf("Enter number elements to be popped in stack 2\n");
     scanf("%d", &n2);
     for(i=1; i<=n2; i++)
    {
     x=pop2(&s);
     printf("Element popped out of 2nd stack is %d\n", x);
    }
 
    printf("Elements in stack 1 are\n");
    display1(&s);
    printf("Elements in stack 2 are\n");
    display2(&s);
}

/* Enter number elements for stack 1
 5
 Enter value
 1
 Enter value
 2
 Enter value
 3
 Enter value
 4
 Enter value
 5
 Enter number elements for stack 2
 5
 Enter value
 6
 Enter value
 7
 Enter value
 8
 Enter value
 9
 Enter value
 10
 Enter number elements to be popped in stack 1
 3
 Element popped out of 1st stack is 5
 Element popped out of 1st stack is 4
 Element popped out of 1st stack is 3
 Enter number elements to be popped in stack 2
 2
 Element popped out of 2nd stack is 10
 Element popped out of 2nd stack is 9
 Elements in stack 1 are
 2
 1
 Elements in stack 2 are
 8
 7
 6
*/
