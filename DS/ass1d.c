//
//  ass1d.c
//  
//
//  Created by Kevlyn Kadamala on 07/08/18.
//

#include<stdio.h>
#include<stdlib.h>
#define MAX 20

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
    else if(q->front==q->rear)
    {
        x=q->a[q->rear];
        q->front=q->rear=-1;
        return x;
    }
    else
    {
        x=q->a[q->front];
        q->front++;
        return x;
    }
}

void display(que *q)   //Function to display contents of queue
{
    int i;
    for(i=q->front; i<=q->rear; i++)
        printf("%d ", q->a[i]);
    printf("\n");
}

void arrange(que *q, int n) //To arrange elements
{
    que p;
    init_queue(&p);
    int mid=n/2;
    int i, j;
    i=0, j=mid;
    while(i!=(mid+1) && j!=n)
    {
        int x=q->a[i];
        int y=q->a[j];
        enque(&p,x);
        enque(&p,y);
        i++; j++;
    }
     printf("Elements after arrangement are\n");
    display(&p);
    
}

void main()
{
    que q;
    init_queue(&q);
    int n, x;
    printf("Enter even number of elements to be entered\n");
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        printf("Enter element to be enqueued\n");
        scanf("%d", &x);
        enque(&q, x);
    }
    printf("Elements before arrangement are\n");
    display(&q);
    arrange(&q,n);
    
    
}
