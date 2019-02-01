//
//  ass1a.c
//  
//
//  Created by Kevlyn Kadamala on 06/08/18.
//

#include <stdio.h>
#include<stdio.h>
#include<stdlib.h>
#define MAX 50

typedef struct stack    //Stack declaration
{
    char a[MAX];
    int top;
}stk;

void init_stack(stk *p) //Stack initialization function
{
    (*p).top=-1;
}

int isfull(int p)   //To check if stack is full
{
    if(p==MAX-1)
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

void push(stk *p, char x)    //To push values into stack
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

char pop(stk *p) //To pop values out of stack
{
    char x;
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
        printf("%c", (*p).a[i]);
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

void convert(char exp[])
{
    stk q, r;
    char p, pre;
    init_stack(&q);
    init_stack(&r);
    int i=0;
    while(exp[i]!='\0')
    {
        if(exp[i]=='-' && exp[i+1]=='(')
        {
            printf("yes\n");
            push(&q, '-');
            i=i+2;
            while(exp[i]!='(' && exp[i]!='\0') //a-(b-c-(d+e))-f a-(b+c)
            {
                if(exp[i]=='+')
                {
                    push(&q, '-');
                    i++;
                }
                else if(exp[i]=='-')
                {
                    push(&q, '+');
                    i++;
                }
                else if(exp[i]==')' || exp[i]=='(' )
                    i++;
                else
                {
                    push(&q, exp[i]);
                    i++;
                }
            }
        }
        else
        {
            if(exp[i]==')' || exp[i]=='(')
                i++;
            else
            {
                push(&q, exp[i]);
                i++;
            }
        }
        
    }
    while(q.top!=-1)
    {
        push(&r, pop(&q));
    }
    display(&r);
     
}

void main()
{
    char exp[50];
    printf("Enter expression\n");
    gets(exp);
    convert(exp);
}

/*
 Enter expression
 warning: this program uses gets(), which is unsafe.
 c+(d-(f-(e-(r-(s-k-i-o)))))
 yes
 yes
 c+d-f+e-r+s-k-i-o
 kad99kev:DS kevlynkadamala$ ./a.out
 Enter expression
 warning: this program uses gets(), which is unsafe.
 r+t-(q-w-e-r-(t-y-u-i-(o-p)))
 yes
 yes
 r+t-q+w+e+r+t-y-u-i-o+p
 */
