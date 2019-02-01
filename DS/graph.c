/*
 Title   : Implementation of graph and its traversals
 Name    : Kevlyn Kadamala
 Roll no.: 8340
 */
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int adj[SIZE][SIZE]={0};

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

void create_adjmat(int n)
{
	int s, d, e, i, j;
	for(i=0; i<n; i++)
	{
		printf("Enter number edges for %d\n", i);
		scanf("%d", &e);
		for(j=0; j<e; j++)
		{  			printf("Enter destination\n");
			scanf("%d", &d);
			adj[i][d]=1;
		}
	}
}

void bfs_mat(int source, int n)
{
	int visited[SIZE]={0};
	int v, i;
	que q;
	init_queue(&q);
	enque(&q,source);
	visited[source]=1;
	while(!isemptyque(&q))
	{
		v=deque(&q);
		printf("%d ", v);
		for(i=0; i<n; i++)
		{
			if(adj[v][i]==1 && visited[i]==0)
			{
                visited[i]=1;
				enque(&q, i);
			}
		} 
	}
	printf("\n");
}

void dfs_mat(int source, int n)
{
    int visited[SIZE]={0};
    int path[SIZE]={0};
    int v, i;
    stk s;
    init_stack(&s);
    push(&s, source);
    visited[source]=1;
    while(!isemptystk(&s))
    {
        v=pop(&s);
        printf("%d ", v);
        for(i=0; i<n; i++)
        {
            if(adj[v][i]==1 && visited[i]==0)
            {
                visited[i]=1;
                push(&s,i);
            }
        }
    }
    printf("\n");
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


/*-------Linked List-----*/

typedef struct node //Node Declaration
{
    int val,posi;
    struct node *next;
}nd;

nd *adj_list[SIZE]={NULL};

nd *add(nd *START, int x) //To insert node at the end
{
    nd *p=(nd *)malloc(sizeof(nd));
    nd *ptr;
    p->val=1;
    p->posi=x;
    if (START==NULL || START->posi > x)
    {
        p->next=START;
        START=p;
    }
    else
    {
        ptr=START;
        while (ptr->next!=NULL && ptr->next->posi < x)
        {
            ptr=ptr->next;
        }
        p->next=ptr->next;
        ptr->next=p;
    }
    return START;
}

/*-------Adjacent List-----*/

void create_adjlist(int n)
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
            adj_list[i]=add(adj_list[i], d);
        }
    }
}

void display_adjlist(int n)
{
    int i,j;
    nd *ptr;
    printf("Adjacency list is\n");
    for(i=0; i<n; i++)
    {
        ptr=NULL;
        ptr=adj_list[i];
        printf("[Index->%d] ", i);
       while(ptr!=NULL)
       {
           printf("[Position->%d] ", ptr->posi);
           ptr=ptr->next;
       }
        printf("\n");
    }
}


void bfs_list(int source, int n)
{
    int visited[SIZE]={0};
    int v, i;
    que q;
    init_queue(&q);
    enque(&q,source);
    visited[source]=1;
    while(!isemptyque(&q))
    {
        v=deque(&q);
        printf("%d ", v);
        for(i=0; i<n; i++)
        {
            nd *ptr=adj_list[v];
            while(ptr!=NULL)
            {
                if(ptr->val==1 && visited[ptr->posi]==0)
                {
                    visited[ptr->posi]=1;
                    enque(&q, ptr->posi);
                }
                ptr=ptr->next;
            }
        }
    }
    printf("\n");
}

void dfs_list(int source, int n)
{
    int visited[SIZE]={0};
    int v, i;
    stk s;
    init_stack(&s);
    push(&s, source);
    visited[source]=1;
    while(!isemptystk(&s))
    {
        v=pop(&s);
        printf("%d ", v);
        nd *ptr=adj_list[v];
        while(ptr!=NULL)
        {
            if(ptr->val==1 && visited[ptr->posi]==0)
            {
                visited[ptr->posi]=1;
                push(&s, ptr->posi);
            }
            ptr=ptr->next;
        }
    }
    printf("\n");
}


void main()
{
	int s,n, i, j, choice=0;
	printf("Enter number nodes\n");
	scanf("%d", &n);
    printf("Enter 1 to create Adjacency matrix or 2 to create Adjacency List\n");
    scanf("%d", &choice);
    if(choice==1)
    {
        create_adjmat(n);
        display_adjmat(n);
        printf("Enter source node for breadth first search\n");
        scanf("%d", &s);
        bfs_mat(s, n);
        printf("Enter source node for depth first search\n");
        scanf("%d", &s);
        dfs_mat(s, n);
    }
    else
    {
        create_adjlist(n);
        display_adjlist(n);
        printf("Enter source node for breadth first search\n");
        scanf("%d", &s);
        bfs_list(s, n);
        printf("Enter source node for depth first search\n");
        scanf("%d", &s);
        dfs_list(s,n);
    }
}

/*
 Enter number nodes
 7
 Enter 1 to create Adjacency matrix or 2 to create Adjacency List
 1
 Enter number edges for 0
 2
 Enter destination
 1
 Enter destination
 2
 Enter number edges for 1
 1
 Enter destination
 4
 Enter number edges for 2
 1
 Enter destination
 3
 Enter number edges for 3
 0
 Enter number edges for 4
 3
 Enter destination
 2
 Enter destination
 5
 Enter destination
 6
 Enter number edges for 5
 0
 Enter number edges for 6
 0
 Adjacency matrix is
 0110000
 0000100
 0001000
 0000000
 0010011
 0000000
 0000000
 Enter source node for breadth first search
 0
 0 1 2 4 3 5 6
 Enter source node for depth first search
 0
 0 2 3 1 4 6 5
 Enter source node
 0
 Enter destination node
 5
 ->0 ->1 ->4 ->5
 */
