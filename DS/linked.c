#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node *next;
}nd;

nd *START=NULL;
int C=0;

void end(nd *p, int x)
{
	nd *newnode=(nd *)malloc(sizeof(nd));
	newnode->info=x;
	if(START==NULL)
		{
			START=newnode;
			newnode->next=NULL;
		}
	else
	{
		newnode->next=NULL;
		nd *ptr;
		ptr=START;
		while(ptr->next!=NULL)
			ptr=ptr->next;
		ptr->next=newnode;
	}
C++;
}

void begin(nd *p, int x)
{
	nd *newnode=(nd *)malloc(sizeof(nd));
	newnode->info=x;
	if(START==NULL)
		{
			START=newnode;
			newnode->next=NULL;
		}
	else
	{
		newnode->next=START;
		START=newnode;
	}
C++;
}

void before(nd *p, int x, int y)
{
	nd *newnode=(nd *)malloc(sizeof(nd));
	nd *ptr, *preptr;
	ptr=START;
	newnode->info=y;
	
	if(START==NULL)
	{
		newnode->next=START->next;
		START=newnode;
	}	
	else if(START->info==x)
		{
			newnode->next=START;			
			START=newnode;
		}
	else
	{
		while(ptr->info!=x && ptr->next!=NULL)
		{
			preptr=ptr;
			ptr=ptr->next;
			
		}
		if(ptr->info!=x && ptr->next==NULL)
			{
				printf("Node not found\n");
				return;
			}
		else
		{
			preptr->next=newnode;
			newnode->next=ptr;
		}
	}
C++;
}

void after(nd *p, int x, int y)
{
	nd *newnode=(nd *)malloc(sizeof(nd));
	nd *ptr;
	ptr=START;
	if(START==NULL)
	{
		START=newnode;
		newnode->info=y;
		newnode->next=NULL;
	}
	else
	{
		while(ptr->info!=x && ptr->next!=NULL)
		{
			ptr=ptr->next;
			
		}
		if(ptr->info==x && ptr->next==NULL)
		{
			newnode->next=NULL;
			ptr->next=newnode;
			newnode->info=y;
		}
		else if(ptr->info!=x && ptr->next==NULL)
			{
				printf("Node not found\n");
				return;
			}
		else
		{
			newnode->next=ptr->next;
			ptr->next=newnode;
			newnode->info=y;	
		}
	}
C++;
}

void display()
{
	nd *ptr;
	if(START==NULL)
		printf("List empty\n");
	else
	{
		ptr=START;
		while(ptr!=NULL)
		{
			printf("%d ", ptr->info);
			ptr=ptr->next;
		}	
	}
	printf("\n");
}

void delete_num(int x)
{
	nd *ptr, *preptr;
	ptr=START;
	int c=1;
	if(START==NULL)
		{
			printf("List Empty\n");
			return;
		}
	else if(x>C)
		{
			printf("Invalid node number\n");
			return;
		}
	else
	{	while(c!=x)
		{
			preptr=ptr;
			ptr=ptr->next;
			c++;
		}
		preptr->next=ptr->next;
		printf("Deleted info= %d\n", ptr->info);
		free(ptr);
	}
	C--;
}

void delete_node(int x)
{
	nd *ptr, *preptr;
	ptr=START;
	if(START==NULL)
		{
			printf("List Empty\n");
			return;
		}
	else if(START->info==x)
	{
		START=ptr->next;
		printf("Deleted info= %d\n", ptr->info);
		free(ptr);
	}
	else if(ptr->info!=x && ptr->next==NULL)
		{
			printf("Node not found\n");
			return;
		}
	else
	{	while(ptr->info!=x)
		{
			preptr=ptr;
			ptr=ptr->next;
		}
		preptr->next=ptr->next;
		printf("Deleted info= %d\n", ptr->info);
		free(ptr);
	}
	C--;
}

void deletedup()
{
    nd *ptr;
    ptr = START;
    while(ptr->next!=NULL){
        if(ptr->info == ptr->next->info){
            nd *next = ptr->next->next;
            free(ptr->next);
            ptr->next = next;
        }
        else{
            ptr = ptr->next;
        }
    }
}

void removeDup()
{
    nd *ptr1, *ptr2, *dup;
    ptr1 = START;
    
    /* Pick elements one by one */
    while (ptr1 != NULL && ptr1->next != NULL){
        ptr2 = ptr1;
        
        /* Compare the picked element with rest
         of the elements */
        while (ptr2->next != NULL){
            /* If duplicate then delete it */
            if (ptr1->info == ptr2->next->info){
                /* sequence of steps is important here */
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(dup);
            }
            else /* This is tricky */
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

void reverse()
{
	nd *curr, *pre=NULL, *next=NULL;
	curr=START;
	while(curr!=NULL)
	{
		next=curr->next;
		curr->next=pre;
		pre=curr;
		curr=next;
		
	}
	START=pre;	
}

nd * insertionSort(nd *start, nd * ptr){
    nd *trav;
    if (start == NULL || start->info < ptr->info)
    {
        ptr->next = start;
        start = ptr;
    }
    else{
        trav = start;
        while((ptr->info < trav->next->info) && trav->next != NULL){ 
            trav = trav->next;
        }
        ptr->next = trav->next;
        trav->next = ptr;
    }
    return start;
}

void sort(){
    nd *current, *start;
    current = START;
    start = NULL;
    while (current != NULL) {
        nd *next = current->next;
        start = insertionSort(start, current);
        current = next;
    }
    START = start;
}

void print(nd *p)
{
    printf("NODE %d\n", p->info);
}

void main()
{
    nd p;
	begin(&p,66);
	begin(&p,20);
    begin(&p,60);
    begin(&p,20);
    begin(&p,66);
    begin(&p,20);
    printf("Normal list\n");
    display();
    printf("After deleting duplicate\n");
    removeDup();
    display();
    printf("After sorting\n");
    sort();
    display();
    printf("After reversing\n");
    reverse();
    display();
}

/*
 20 66 20 60 20 66
 66 20 60 20 66 20
 66 20 60
 */
