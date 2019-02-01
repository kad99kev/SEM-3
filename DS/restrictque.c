/*
 Title   : Static Implementation of Deque
 Name    : Kevlyn Kadamala
 Roll no.: 8340
 */

#include <stdio.h>
#include<stdlib.h>
#define MAX 5

/*------Queue------*/

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

void enque_rear(struct queue *q, int x)  //Function to enqueue
{
    if(q->rear==MAX-1 || q->rear+1 == q->front)
    {
        printf("Queue overflow\n");
    }
    
    else
    {
        if(q->front==-1)
        {
            q->front=0;
        }
        q->rear=q->rear+1;
        q->a[q->rear]=x;
    }
}

void enque_front(struct queue *q, int x)  //Function to enqueue
{
    if(q->front==q->rear+1)
    {
        printf("Queue overflow\n");
    }
    else if(q->front==-1 && q->rear==-1)
    {
        q->front=MAX-1;
        q->a[q->front]=x;
    }
    else if(q->front == 0)
    {
        q->front = MAX-1;
        q->a[q->front]=x;
    }
    else
    {
        q->front=q->front-1;
        q->a[q->front]=x;
    }
}

void deque_front(struct queue *q)  //Function to dequeue
{
    int x;
    if(q->front==-1 && q->rear==-1)
    {
        printf("Queue Underflow\n");
    }
    else if(q->front==q->rear)
    {
        x=q->a[q->front];
        q->front=-1;
        q->rear=-1;
    }
    else if(q->front == MAX-1){
        x = q->a[q->front];
        q->front = 0;
    }
    else
    {
        x=q->a[q->front];
        q->front=q->front+1;
    }
    //printf("FRONT %d REAR %d\n", q->front, q->rear);
    printf("Element dequeued is %d\n", x);
}

void deque_rear(struct queue *q)  //Function to dequeue
{
    int x;
    if(q->front==-1 && q->rear==-1)
    {
        printf("Queue Underflow\n");
    }
    else if(q->front==q->rear)
    {
        x=q->a[q->rear];
        q->front=q->rear=-1;
    }
    else
    {
        x=q->a[q->rear];
        q->rear--;
    }
    printf("Element dequeued is %d\n", x);
}

void display_que(struct queue *q)   //Function to display contents of queue
{
    int i;
    if(q->rear == -1 || q->front == -1){
        printf("List empty\n");
    }
    else{
        for(i=q->front; i<=q->rear; i++)
            printf("%d ", q->a[i]);
        printf("\n");
    }
}

void display_orque(struct queue *q) //Function to display contents of queue
{
    int i;
    if(q->rear == -1 || q->front == -1){
        printf("List empty\n");
    }
    else{
        if(q->front > q->rear){
            for(i=q->front; i<MAX; i++){
                printf("%d ", q->a[i]);
            }
            for(i=0; i<=q->rear; i++){
                printf("%d ", q->a[i]);
            }
        }
        else{
            for(i = q->front; i <= q->rear; i++){
                printf("%d ", q->a[i]);
                //printf("I %d", i);
            }
        }
        printf("\n");
    }
}


void main()
{
    //ir->input restricted; or->output restricted
    struct queue irque, orque;
    init_queue(&irque);
    init_queue(&orque);
    int ch=0, check=0, x;
    printf("Enter\n1. For input restricted queue OR 2. For output restricted queue\n");
    scanf("%d", &ch);
    switch (ch)
    {
        case 1:
        {
            do
            {
                printf("Enter\n1. To enqueue\n2. To dequeue from front\n3. To dequeue from rear\n4. To exit\n");
                scanf("%d", &check);
                switch (check)
                {
                    case 1:
                    {
                        printf("Enter element to be enqueued\n");
                        scanf("%d", &x);
                        enque_rear(&irque, x);
                        break;
                    }
                    case 2:
                    {
                        deque_front(&irque);
                        break;
                    }
                    case 3:
                    {
                        deque_rear(&irque);
                        break;
                    }
                    case 4:
                    {
                        check=0;
                        break;
                    }
                        
                    default: printf("Invalid entry\n");
                        break;
                }
            }while(check!=0);
            printf("Elements in the queue are\n");
            display_que(&irque);
        }
            break;
            
        case 2:
        {
            do
            {
                printf("Enter\n1. To enqueue from front\n2 To enqueue from rear\n3. To dequeue\n4. To exit\n");
                scanf("%d", &check);
                switch (check)
                {
                    case 1:
                    {
                        printf("Enter element to be enqueued\n");
                        scanf("%d", &x);
                        enque_front(&orque, x);
                        break;
                    }
                    case 2:
                    {
                        printf("Enter element to be enqueued\n");
                        scanf("%d", &x);
                        enque_rear(&orque, x);
                        break;
                    }
                    case 3:
                    {
                        deque_front(&orque);
                        break;
                    }
                    case 4:
                    {
                        check=0;
                        break;
                    }
                        
                    default: printf("Invalid entry\n");
                        break;
                }
            }while(check!=0);
            printf("Elements in the queue are\n");
            display_orque(&orque);
        }
            break;
            
        default: printf("Invalid entry\n");
            break;
    }

}

/*
 //For input restricted static queue\\
 Enter
 1. For input restricted queue OR 2. For output restricted queue
 1
 Enter
 1. To enqueue
 2. To dequeue from front
 3. To dequeue from rear
 4. To exit
 1
 Enter element to be enqueued
 10
 Enter
 1. To enqueue
 2. To dequeue from front
 3. To dequeue from rear
 4. To exit
 1
 Enter element to be enqueued
 20
 Enter
 1. To enqueue
 2. To dequeue from front
 3. To dequeue from rear
 4. To exit
 1
 Enter element to be enqueued
 30
 Enter
 1. To enqueue
 2. To dequeue from front
 3. To dequeue from rear
 4. To exit
 1
 Enter element to be enqueued
 40
 Enter
 1. To enqueue
 2. To dequeue from front
 3. To dequeue from rear
 4. To exit
 1
 Enter element to be enqueued
 50
 Enter
 1. To enqueue
 2. To dequeue from front
 3. To dequeue from rear
 4. To exit
 2
 Element dequeued is 10
 Enter
 1. To enqueue
 2. To dequeue from front
 3. To dequeue from rear
 4. To exit
 3
 Element dequeued is 50
 Enter
 1. To enqueue
 2. To dequeue from front
 3. To dequeue from rear
 4. To exit
 4
 Elements in the queue are
 20 30 40
 
 //For output restricted sttic queue\\
 Enter
 1. For input restricted queue OR 2. For output restricted queue
 2
 Enter
 1. To enqueue from front
 2 To enqueue from rear
 3. To dequeue
 4. To exit
 1
 Enter element to be enqueued
 10
 Enter
 1. To enqueue from front
 2 To enqueue from rear
 3. To dequeue
 4. To exit
 2
 Enter element to be enqueued
 20
 Enter
 1. To enqueue from front
 2 To enqueue from rear
 3. To dequeue
 4. To exit
 1
 Enter element to be enqueued
 30
 Enter
 1. To enqueue from front
 2 To enqueue from rear
 3. To dequeue
 4. To exit
 2
 Enter element to be enqueued
 40
 Enter
 1. To enqueue from front
 2 To enqueue from rear
 3. To dequeue
 4. To exit
 1
 Enter element to be enqueued
 50
 Enter
 1. To enqueue from front
 2 To enqueue from rear
 3. To dequeue
 4. To exit
 3
 Element dequeued is 50
 Enter
 1. To enqueue from front
 2 To enqueue from rear
 3. To dequeue
 4. To exit
 3
 Element dequeued is 30
 Enter
 1. To enqueue from front
 2 To enqueue from rear
 3. To dequeue
 4. To exit
 4
 Elements in the queue are
 10 20 40
 */
