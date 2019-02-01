/*
 Title   : Implementation of graph its topographical sort
 Name    : Kevlyn Kadamala
 Roll no.: 8340
 */

#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int adj[SIZE][SIZE]={0};
int degree[SIZE]={0};

/*-------Stack-----*/
typedef struct stack
{
    int a[SIZE], top;
}stk;

void init_stack(stk *p)
{
    p->top=-1;
}

int isfull(stk *p)
{
    if(p->top==SIZE-1)
    return 1;
    else
    return 0;
}

int isemptystk(stk *p)
{
    if(p->top==-1)
    return 1;
    else
    return 0;
}

void push(stk *p, int x)
{
    if(isfull(p))
    {
        printf("Stack overflow\n");
    }
    else
    {
        p->a[++p->top]=x;
    }
}

int pop(stk *p)
{
    int x;
    if(isemptystk(p))
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
/*-------Queue-----*/

typedef struct queue
{
    int a[SIZE];
    int front;
    int rear;
}que;

void init_queue(struct queue *q)
{
    q->front=-1;
    q->rear=-1;
}

void enque(struct queue *q, int x)
{
    if(q->rear==SIZE-1)
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

int deque(struct queue *q)
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

int isemptyque(que *p)
{
    if(p->front==-1 && p->rear==-1)
    return 1;
    else
    return 0;
}

/*-------Adjacent Matrix-----*/

void createdegree(int n)
{
    int i, j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(adj[j][i]==1)
                degree[i]++;
        }
    }
    for(i=0; i<n; i++)
    {
        printf("NODE-%d DEGREE-%d\n", i, degree[i]);
    }
}

void create_adjmat(int n)
{
    int s, d, e, i, j;
    for(i=0; i<n; i++)
    {
        printf("Enter number edges for %d\n", i);
        scanf("%d", &e);
        for(j=0; j<e; j++)
        {
            printf("Enter destination\n");
            scanf("%d", &d);
            adj[i][d]=1;
        }
    }
    createdegree(n);
}


void display_adjmat(int n)
{
    int i,j;
    printf("Adjacency matrix is\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d", adj[i][j]);
        }
        printf("\n");
    }
}



void topo(int n)
{
    que q, t;
    int visited[SIZE]={0};
    int i=0, j=0, p;
    init_queue(&q);
    init_queue(&t);
    do
    {
        for(i=0; i<n; i++) //Check for nodes with 0 degrees
        {
            if(degree[i]==0 && visited[i]==0)
            {
                visited[i]=1;
                enque(&q, i);
            }
        }
        p=deque(&q); //Dequeues the first node
        enque(&t, p);
        for(i=0; i<n; i++)
        {
            if(adj[p][i]==1) //Reduces the degree of the neighbouring nodes
            {
                degree[i]--;
            }
        }
        for(i=0; i<n; i++) //Checks for nodes with 0 degrees again
        {
            if(degree[i]==0 && visited[i]==0)
            {
                visited[i]=1;
                enque(&q, i);
            }
        }
    }while(!isemptyque(&q));
    
    printf("The topographical sort of the graph is\n");
    while(!isemptyque(&t))
    {
        printf("%d ", deque(&t));
    }
    printf("\n");
}

void main()
{
    int s,n, i, j, choice=0;
    printf("Enter number nodes\n");
    scanf("%d", &n);
    create_adjmat(n);
    display_adjmat(n);
    topo(n);
    
}

/*
 Enter number nodes
 7
 Enter number edges for 0
 1
 Enter destination
 1
 Enter number edges for 1
 3
 Enter destination
 2
 Enter destination
 3
 Enter destination
 4
 Enter number edges for 2
 1
 Enter destination
 4
 Enter number edges for 3
 1
 Enter destination
 4
 Enter number edges for 4
 1
 Enter destination
 5
 Enter number edges for 5
 0
 Enter number edges for 6
 1
 Enter destination
 3
 NODE-0 DEGREE-0
 NODE-1 DEGREE-1
 NODE-2 DEGREE-1
 NODE-3 DEGREE-2
 NODE-4 DEGREE-3
 NODE-5 DEGREE-1
 NODE-6 DEGREE-0
 Adjacency matrix is
 0100000
 0011100
 0000100
 0000100
 0000010
 0000000
 0001000
 The topographical sort of the graph is
 0 6 1 2 3 4 5
 */
