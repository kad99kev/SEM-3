//
//  plab3.c
//  
//
//  Created by Kevlyn Kadamala on 20/08/18.
//

#include <stdio.h>
#include<stdlib.h>
#define MAX 5


 typedef struct queue    //Declaration of queue
{
    int a[MAX];
    int front;
    int rear;
}que;

void init_queue(que *q)    //Queue initialization function
{
    q->front=-1;
    q->rear=-1;
}

void enque(que *q, int x)  //Function to enqueue
{
    if(q->rear==MAX-1)
    {
        printf("Queue overflow\n");
    }
    else
    {
        q->rear++;
        q->a[q->rear]=x;
        if(q->front==-1)
            q->front=0;
    }
}

int deque(que *q)  //Function to dequeue
{
    int x;
    if(q->front==-1 && q->rear==-1)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    else if(q->rear==q->front)
    {
        x=q->a[q->rear];
        q->front=q->rear=-1;
        return x;
    }
    else
    {
        x=q->a[q->rear];
        q->rear--;
        return x;
    }
}

void displayque(que *q)   //Function to display contents of queue
{
    int i;
    for(i=q->front; i<MAX; i++)
        printf("%d ", q->a[i]);
    printf("\n");
}

typedef struct stack    //Stack declaration
{
    int a[MAX], top;
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

void displaystk(stk *p)    //To display contents of stack
{
    int i;
    for(i=(*p).top; i>=0; i--)
        printf("%d\n", (*p).a[i]);
}

int main(void)
{
    int x, i;
    que q;
    stk s;
    init_queue(&q);
    init_stack(&s);
    for(i=1; i<=MAX; i++)
    {
        printf("Enter value\n");
        scanf("%d", &x);
        enque(&q,x);
    }
    printf("Values in queue are\n");
    displayque(&q);
    x=q.rear;
    int y=q.front;
    while(x>y-1)
    {
        push(&s,deque(&q));
        x--;
    }
    printf("Values in stack are\n");
    displaystk(&s);
}

