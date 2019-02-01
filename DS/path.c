#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

int graph[10][10]={0};

struct queue
{
	int front,rear;
	int a[100];
};

struct stack
{
	int top;
	int a[100];
};

void initstk(struct stack *s)
{
	s->top=-1;
}

void push(struct stack *s,int x)
{
	if(s->top==SIZE-1)
	{
		printf("Stack overflow\n");
	}
	else 
	{
		s->top=s->top+1;
		s->a[s->top]=x;
	}
}

int pop(struct stack *s)
{
	int x;
	if(s->top==-1)
	{
		printf("Stack underflow\n");
	}
	else
	{
		x=s->a[s->top];
		s->top=s->top-1;
		return x;
	}
}	
int isEmpty(struct queue *q)
{
	if(q->rear==-1)
		return 1;
	else
		return 0;
}

int isEmptystk(struct stack *s)
{
	if(s->top==-1)
		return 1;
	else
		return 0;
}

void init(struct queue *q)
{
	q->front=-1;
	q->rear=-1;
}

void enque(struct queue *q, int x)
{
	if(q->rear==SIZE)
	{
		printf("Queue full\n");
	}
	else if(q->front==-1 && q->rear==-1)
	{
		q->front=0;
		q->rear=0;
		q->a[q->rear]=x;
	}
	else
	{
		q->rear=q->rear+1;
		q->a[q->rear]=x;
	}
}

int deque(struct queue *q)
{
	int x;
	if(q->front==-1)
	{
		printf("Queue empty\n");
	}
	else if(q->front==q->rear)
	{
		x=q->a[q->front];
		q->front=-1;
		q->rear=-1;
		return x;	
	}
	else
	{
		x=q->a[q->front];
		q->front=q->front+1;
		return x;
	}
}

void path(int source, int d, int n)
{
	int visited[SIZE]={0};
	int visit[SIZE]={0}; //to check if element is gone into stack to display path
	int i,x,y,count=0,c=0;
	struct stack s;
	struct stack p;
	initstk(&s);
	initstk(&p);
	visited[source]=1;
	push(&s,source);
	while(!isEmptystk(&s) && p.a[p.top]!=d)
	{
		count=0;
		x=pop(&s);
		for(i=0;i<n;i++)
		{	
			if(graph[x][i]==1 && visited[i]==0)
			{
				push(&s,i);
				visited[i]=1;
				count++; // counts whether node has a neighbour or no
			}
		}
		
		push(&p,x);
		visit[x]=1;
		
		if(count==0 && p.a[p.top]!=d)
		{
                c=0;
				y=pop(&p);
				y=pop(&p);
				for(i=0;i<n;i++)
				{
					if(visit[i]==0 && graph[y][i]==1)
					{
						c++;// to check is previous node has any more neighbours than the popped out element
					}
				}
				if(c!=0)
				{
					push(&p,y);//if it has more neighbours than only popped out element push it back to the new stack
				}	
			
		}
		
	}
    while(!isEmptystk(&p))
    {
        printf("%d<-",pop(&p));
    }
    printf("\n");
}

void main()
{
 	int e,s,d,i,j,c,n,source,choice,des;
 	printf("Enter size of matrix\n");
 	scanf("%d",&n);
 	printf("Enter\n1. Directional graph\n2. Bidirectional graph\n");
 	scanf("%d",&choice);
 	do
 	{
	 		printf("Enter source & destination\n");
	 		scanf("%d %d",&s,&d);
	 		graph[s][d]=1;
	 		if(choice==2)
	 		{
	 			graph[d][s]=1;
 			}
 			printf("Enter 1 to stop\n");
 			scanf("%d",&c);
	 }while(c!=1);
	 		
	printf("Adjacency matrix is:\n"); 	
 	for(i=0;i<n;i++)
 	{
 		for(j=0;j<n;j++)
 		{
 			printf("%d ",graph[i][j]);
 		}
 		printf("\n");
 	}
 	printf("Enter source\n");
 	scanf("%d",&source);
 	printf("Enter destination\n");
 	scanf("%d",&des);
 	path(source,des,n);
 }

/*
Enter size of matrix
8
Enter
1. Directional graph
2. Bidirectional graph
2
Enter source & destination
1
4
Enter 1 to stop
2
Enter source & destination
1
5
Enter 1 to stop
2
Enter source & destination
1
0
Enter 1 to stop
2
Enter source & destination
0
3
Enter 1 to stop
2
Enter source & destination
3
4
Enter 1 to stop
2
Enter source & destination
2
4
Enter 1 to stop
2
Enter source & destination
2
7
Enter 1 to stop
2
Enter source & destination
5
6
Enter 1 to stop
1
Adjacency matrix is:
0 1 0 1 0 0 0 0 
1 0 0 0 1 1 0 0 
0 0 0 0 1 0 0 1 
1 0 0 0 1 0 0 0 
0 1 1 1 0 0 0 0 
0 1 0 0 0 0 1 0 
0 0 0 0 0 1 0 0 
0 0 1 0 0 0 0 0 
Enter source
1
Enter destination
7
1->4->2->7
*/
