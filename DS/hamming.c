#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define SIZE 100

typedef struct node
{
	int info;
	struct node *next;
	int position;
}nd;

nd *START=NULL;
int node_pos=1;

void insertBeg(nd *newnode, int x)
{
		
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->info=x;
	newnode->next=NULL;
	if(START==NULL)
	{
		START=newnode;
		newnode->next=START;
	}
	else if(START->next==NULL)
    	{
        	START->next=newnode;
        	newnode->next=NULL;
        	START=newnode;
    	}
	else
	{
		newnode->next=START;
		START=newnode;
	};
}



void insertEnd(struct node *newnode, int x)
{	
		
	struct node *ptr=START;	
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->info=x;
	newnode->next=NULL;
	newnode->position=node_pos;
	if(START==NULL)
	{
		START=newnode;
		newnode->next=NULL;
	}
	else
	{
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
			
		}
		ptr->next=newnode;
		newnode->next=NULL;
	}
    node_pos++;
}

void before(struct node *newnode, int newnodeinfo, int giveninfo)
{
		
	struct node *ptr=START;	
	struct node *pre=START;	
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->info=newnodeinfo;
	newnode->next=NULL;
	if(START==NULL)
	{
		printf("No nodes in linked list\n");		
	}
	else
	{
		while(ptr->next!=NULL && ptr->info!=giveninfo)
		{
			pre=ptr;			
			ptr=ptr->next;
			
		}
		if(ptr==START)
		{
			newnode->next=START;
			START=newnode;
		}
		else if(ptr->next!=NULL)
		{
			newnode->next=pre->next;
			pre->next=newnode;
					
		}
		else
		{
			printf("Node not found\n");
		}	
	}
	
}

void afterFirst(struct node *newnode, int x)
{
		
	struct node *ptr=START;	
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->info=x;
	newnode->next=START->next;
	START->next=newnode;
}

void displayGenerator()
{
	nd *ptr=START;
	printf("Required Hamming Code is:\n");
	while(ptr!=NULL)
	{
		printf("%d ",ptr->info);
		ptr=ptr->next;
	}
    printf("\n");
}

void displayChecker(int pos)
{
    nd *ptr;
    ptr=START;
        if(pos==0)
        {
            printf("No error\n");
            printf("Original code is\n");
            while(ptr!=NULL)
            {
                if(ptr->position==3||ptr->position==5||ptr->position==6||ptr->position==7)
                {
                   printf("%d ",ptr->info);
                }
                ptr=ptr->next;
            }
        }
        else
        {
            printf("Error at position %d\n",pos);
            printf("Original code is\n");
            while(ptr!=NULL)
            {
                if(ptr->position==3||ptr->position==5||ptr->position==6||ptr->position==7)
                {
                    if(ptr->position==pos)
                    {
                        if(ptr->info==1)
                            printf("0 ");
                        else
                            printf("1 ");
                    }
                    else
                    {
                        printf("%d ",ptr->info);
                    }
                }
                ptr=ptr->next;
            }
        }
        printf("\n");
}

int oddEvenGenerator(int pos1, int pos2, int pos3)
{
    int count=0;
    nd *ptr;
    ptr=START;
    while(ptr!=NULL)
    {
        if(ptr->position==pos1||ptr->position==pos2||ptr->position==pos3)
        {
            if(ptr->info==1)
            {
                count++;
            }
        }
        ptr=ptr->next;
    }
    return count;
}

int oddEvenChecker(int pos1, int pos2, int pos3, int pos4)
{
    int count=0;
    nd *ptr;
    ptr=START;
    while(ptr!=NULL)
    {
        if(ptr->position==pos1||ptr->position==pos2||ptr->position==pos3||ptr->position==pos4)
        {
            if(ptr->info==1)
            {
                count++;
            }
        }
        ptr=ptr->next;
    }
    return count;
}


void parityGenerator(int choice)
{
	struct node n[SIZE];
	int count=0;
	int j=0;
	int p1,p2,p3;
	struct node *ptr=START;
	if(choice==1)// odd parity hamming code
	{
        count=oddEvenGenerator(1,2,4); //For first parity bit we get we have to check 1,3,5,7 of the hamming code block so that corresponds to 1,2 and 4th bit of info
		if(count%2==0)// if odd number of 1's Parity bit will be 0
		{
			p1=1;
		}
		else
		{
			p1=0;// if even number of 1's Parity bit will be 1
		}
		ptr=START;
		count=0;
        count=oddEvenGenerator(1,3,4); //For second parity bit we get we have to check 2,3,6,7 of the hamming code block so that corresponds to 1,3 and 4th bit of info
		if(count%2==0)
		{
			p2=1;
		}
		else
		{
			p2=0;
		}
		ptr=START;
		count=0;
        count=oddEvenGenerator(2,3,4); //For first parity bit we get we have to check 4,5,6,7 of the hamming code block so that corresponds to 2,3 and 4th bit of info
		if(count%2==0)
		{
			p3=1;
		}
		else
		{
			p3=0;
		}
		
		afterFirst(&n[j],p3);
		j++;
		insertBeg(&n[j],p2);
		j++;
		insertBeg(&n[j],p1);
	}
	else
	{
        count=oddEvenGenerator(1,2,4);
		if(count%2==0)                                           
		{
			p1=0;
		}
		else
		{
			p1=1;
		}
		ptr=START;
		count=0;
        count=oddEvenGenerator(1,3,4);
		if(count%2==0)                                           
		{
			p2=0;
		}
		else
		{
			p2=1;
		}
		ptr=START;
		count=0;
        count=oddEvenGenerator(2,3,4);
		if(count%2==0)                                           
		{
			p3=0;
		}
		else
		{
			p3=1;
		}
		
		afterFirst(&n[j],p3);//parity bit 3 is placed after first info bit
		j++;
		insertBeg(&n[j],p2);//parity bit 2 is placed before first info bit
		j++;
		insertBeg(&n[j],p1);//parity bit 1 is placed before parity bit 2
	}
	
    displayGenerator();
}

void parityChecker(int choice)
{
    int count=0;
    int j=0;
    int p1,p2,p3, pos;
    struct node *ptr=START;
    if(choice==1)// odd parity hamming code
    {
        count=oddEvenChecker(1,3,5,7); //For first parity bit we get we have to check 1,3,5,7 of the hamming code block so that corresponds to 1,2 and 4th bit of info
        if(count%2==0)// if odd number of 1's Parity bit will be 0
        {
            p3=1;
        }
        else
        {
            p3=0;// if even number of 1's Parity bit will be 1
        }
        ptr=START;
        count=0;
        count=oddEvenChecker(2,3,6,7); //For second parity bit we get we have to check 2,3,6,7 of the hamming code block so that corresponds to 1,3 and 4th bit of info
        if(count%2==0)
        {
            p2=1;
        }
        else
        {
            p2=0;
        }
        ptr=START;
        count=0;
        count=oddEvenChecker(4,5,6,7); //For first parity bit we get we have to check 4,5,6,7 of the hamming code block so that corresponds to 2,3 and 4th bit of info
        if(count%2==0)
        {
            p1=1;
        }
        else
        {
            p1=0;
        }
        pos=p1*pow(2,2)+p2*pow(2,p2*1)+p3*pow(2,0);
        
    }
    else
    {
        count=oddEvenChecker(1,3,5,7);
        if(count%2==0)
        {
            p3=0;
        }
        else
        {
            p3=1;
        }
        ptr=START;
        count=0;
        count=oddEvenChecker(2,3,6,7);
        if(count%2==0)
        {
            p2=0;
        }
        else
        {
            p2=1;
        }
        ptr=START;
        count=0;
        count=oddEvenChecker(1,3,5,7);
        if(count%2==0)
        {
            p1=0;
        }
        else
        {
            p1=1;
        }
        pos=p1*pow(2,2)+p2*pow(2,p2*1)+p3*pow(2,0);
    }
    displayChecker(pos);

}

void generate()
{
    int i=0, choice;
    nd s[SIZE];
    char bits[10];
    printf("Enter 4 bits of data\n");
    scanf("%s", bits);
    while(bits[i]!='\0')
    {
        insertEnd(&s[i], (int)bits[i]-'0');
        i++;
    }
    printf("Enter:\n1-Odd parity Hamming Code\n2-Even parity Hamming Code\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        {
            parityGenerator(choice);
            break;
        }
        case 2:
        {
            parityGenerator(choice);
            break;
        }
    }
}

void checker()
{
    int i=0, choice;
    nd s[SIZE];
    char bits[10];
    printf("Enter 7 bits of data\n");
    scanf("%s", bits);
    while(bits[i]!='\0')
    {
        insertEnd(&s[i], (int)bits[i]-'0');
        i++;
    }
    printf("Enter:\n1-Check Odd parity Hamming Code\n2-Check Even parity Hamming Code\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        {
            parityChecker(choice);
            break;
        }
        case 2:
        {
            parityChecker(choice);
            break;
        }
    }
}

void main()
{
	
	 int choice;
    printf("Enter\n1. To generate Hamming Code\n2. To check Hamming Code\n");
    scanf("%d", &choice);
    if(choice==1)
    {
        generate();
    }
    else
    {
        checker();
    }
	
}

/*
Enter 4 bits of data
0
1
1
0
Enter:
1-Odd parity Hamming Code
2-Even parity Hamming Code
2
Required Hamming Code is:
1100110
*/
