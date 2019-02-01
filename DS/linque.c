 /*
 Title   : Static Implementation of Linear queue
 Name    : Kevlyn Kadamala
 Roll no.: 8340
 */

#include<stdio.h>
#include<stdlib.h>
#define MAX 5

struct queue    //Declaration of queue
{
	int a[MAX];
	int front;
	int rear;
};

void init_queue(struct queue *q)    //Queue initialization function
{
 q->front=-1;
 q->rear=-1;
}

void enque(struct queue *q, int x)  //Function to enqueue
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

void deque(struct queue *q)  //Function to dequeue
{
	int x;
	if(q->front==-1 && q->rear==-1)
		{
			printf("Queue Underflow\n");
			return;
		}
	else if(q->front==q->rear)
	{
		x=q->a[q->rear];
		q->front=q->rear=-1;
	}
	else
	{
		x=q->a[q->front];
		q->front++;
	}
    printf("Value dequeued is %d\n", x);
}

void display(struct queue *q)   //Function to display contents of queue
{
	int i;
	for(i=q->front; i <= q->rear; i++)
		printf("%d ", q->a[i]);
    printf("\n");
}

void main()
{
	int x, n, i;
	struct queue q;
	init_queue(&q);
    printf("Enter number of values to be entered (MAX is 5)\n");
    scanf("%d", &n);
    printf("Enter values to be enqueued\n");
    for(i=1; i<=n; i++)x\
    {
        scanf("%d", &x);
        enque(&q,x);
    }
    printf("Enter number of values to be dequeued\n");
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        deque(&q);
    }
    printf("Values in queue are\n");
    display(&q);
		
}

/*
 Enter number of values to be entered (MAX is 5)
 5
 Enter values to be enqueued
 1
 2
 3
 4
 5
 Enter number of values to be dequeued
 3
 Value dequeued is 1
 Value dequeued is 2
 Value dequeued is 3
 Values in queue are
 4 5
 */
