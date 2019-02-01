#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct node
{
	char name[50];
	int apps;	
	int goals;
	int assists;
	int yellow;
    	int red;
	float val;
	struct node *next;
}plr;

plr *read(struct node *start)
{
    char t [2];
	plr *ptr=start;
	plr *newplayer;
	newplayer=(struct node *)malloc(sizeof(struct node));
	newplayer->next=NULL;
    gets(t);
	printf("Enter name of player:\n");
	gets(newplayer->name);
	printf("Enter number of appearances:\n");
	scanf("%d",&newplayer->apps);
	printf("Enter number of goals scored:\n");
	scanf("%d",&newplayer->goals);
	printf("Enter number of assists given:\n");
	scanf("%d",&newplayer->assists);
	printf("Enter number of yellow cards\n");
	scanf("%d",&newplayer->yellow);
    	printf("Enter number of red cards\n");
    	scanf("%d",&newplayer->red);
    newplayer->val = 0.5*newplayer->apps + 5*newplayer->goals + 3*newplayer->assists - newplayer->yellow - 2*newplayer->red;
	if(start==NULL)
	{
		start=newplayer;
		newplayer->next=NULL;
	}
	else
	{
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=newplayer;
		newplayer->next=NULL;
	}// all new players are added at the end of last node
    return start;
}

void display(plr *start)
{
	struct node *ptr=start;
    printf("Name | Apps | Goals | Assists | Yellow Cards | Red Cards | Value\n");
	while(ptr!=NULL)
	{
		printf("%s | %d | %d | %d | %d | %d | %f \n",ptr->name,ptr->apps,ptr->goals,ptr->assists,ptr->yellow,ptr->red,ptr->val);
        printf("-----------------------\n");
		ptr=ptr->next;
	}
}

plr *sortName(plr *start, plr *ptr)
{
    plr *current;
    /* Special case for the head end */
    if (start == NULL || strcmp(start->name, ptr->name) > 0)
    {
        ptr->next = start;
        start = ptr;
    }
    else
    {
        /* Locate the node before the point of insertion */
        current = start;
        while (current->next!=NULL && strcmp(current->name, ptr->name) < 0)
        {
            current = current->next;
        }
        ptr->next = current->next;
        current->next = ptr;
    }
    return start;
}

plr *sortApps(plr *start, plr *ptr)
{
    plr *current;
    /* Special case for the head end */
    if (start == NULL || (start)->apps < ptr->apps)
    {
        ptr->next = start;
        start = ptr;
    }
    else
    {
        /* Locate the node before the point of insertion */
        current = start;
        while (current->next!=NULL && current->next->apps > ptr->apps)

        {
            current = current->next;
        }
        ptr->next = current->next;
        current->next = ptr;
    }
    return start;
}

plr *sortGoals(plr *start, plr *ptr)
{
    plr *current;
    /* Special case for the head end */
    if (start == NULL || (start)->goals < ptr->goals)
    {
        ptr->next = start;
        start = ptr;
    }
    else
    {
        /* Locate the node before the point of insertion */
        current = start;
        while (current->next!=NULL && current->next->goals > ptr->goals)
        {
            current = current->next;
        }
        ptr->next = current->next;
        current->next = ptr;
    }
    return start;
}

plr *sortAssists(plr *start, plr *ptr)
{
    plr *current;
    /* Special case for the head end */
    if (start == NULL || (start)->assists < ptr->assists)
    {
        ptr->next = start;
        start = ptr;
    }
    else
    {
        /* Locate the node before the point of insertion */
        current = start;
        while (current->next!=NULL && current->next->assists > ptr->assists)
        {
            current = current->next;
        }
        ptr->next = current->next;
        current->next = ptr;
    }
    return start;
}

plr *sortYellow(plr *start, plr *ptr)
{
    plr *current;
    /* Special case for the head end */
    if (start == NULL || (start)->yellow < ptr->yellow)
    {
        ptr->next = start;
        start = ptr;
    }
    else
    {
        /* Locate the node before the point of insertion */
        current = start;
        while (current->next!=NULL && current->next->yellow > ptr->yellow)
        {
            current = current->next;
        }
        ptr->next = current->next;
        current->next = ptr;
    }
    return start;
}

plr *sortRed(plr *start, plr *ptr)
{
    plr *current;
    /* Special case for the head end */
    if (start == NULL || (start)->red < ptr->red)
    {
        ptr->next = start;
        start = ptr;
    }
    else
    {
        /* Locate the node before the point of insertion */
        current = start;
        while (current->next!=NULL && current->next->red > ptr->red)
        {
            current = current->next;
        }
        ptr->next = current->next;
        current->next = ptr;
    }
    return start;
}

plr *sortVal(plr *start, plr *ptr)
{
    plr *current;
    /* Special case for the head end */
    if (start == NULL || (start)->val < ptr->val)
    {
        ptr->next = start;
        start = ptr;
    }
    else
    {
        /* Locate the node before the point of insertion */
        current = start;
        while (current->next!=NULL && current->next->val > ptr->val)
        {
            current = current->next;
        }
        ptr->next = current->next;
        current->next = ptr;
    }
    return start;
}


plr *sort(plr *start, int a)
{
    // Initialize sorted linked list
    plr *sorted=NULL;
    
    // Traverse the given linked list and insert every
    // node to sorted
    plr *current = start;
       switch(a)
        {
            case 1:
            {
                while (current != NULL)
                {
                    plr *next = current->next;// Store next for next iteration
                    sorted=sortName(sorted, current);  // insert current in sorted linked list
                    current = next; // Update current
                }
                break;
            }
            
            case 2:
            {
                while (current != NULL)
                {
                    plr *next = current->next;// Store next for next iteration
                    sorted=sortApps(sorted, current);  // insert current in sorted linked list
                    current = next; // Update current
                }
                break;
            }
          
            case 3:
            {
                while (current != NULL)
                {
                    plr *next = current->next;// Store next for next iteration
                    sorted=sortGoals(sorted, current);  // insert current in sorted linked list
                    current = next; // Update current
                }
                break;
            }
                
            case 4:
            {
                while (current != NULL)
                {
                    plr *next = current->next;// Store next for next iteration
                    sorted=sortAssists(sorted, current);  // insert current in sorted linked list
                    current = next; // Update current
                }
                break;
            }
                
            case 5:
            {
                while (current != NULL)
                {
                    plr *next = current->next;// Store next for next iteration
                    sorted=sortYellow(sorted, current);  // insert current in sorted linked list
                    current = next; // Update current
                }
                break;
            }
                
            case 6:
            {
                while (current != NULL)
                {
                    plr *next = current->next;// Store next for next iteration
                    sorted=sortRed(sorted, current);  // insert current in sorted linked list
                    current = next; // Update current
                }
                break;
            }
                
            case 7:
            {
                while (current != NULL)
                {
                    plr *next = current->next;// Store next for next iteration
                    sorted=sortVal(sorted, current);  // insert current in sorted linked list
                    current = next; // Update current
                }
                break;
            }
                
        }
    
    // Update head_ref to point to sorted linked list
    start=sorted;
    display(start);
    return start;
}

plr *team(plr *start,int t)
{
    int  chtm3, a;
    printf("Select\n1. To display players entered\n2. To sort by name\n3. To sort by number of appearances\n4. To sort by number of goals scored\n5. To sort by number of assists\n6. To sort by number of yellow cards\n7. To sort by number of red cards\n8. To sort by current market value\n9. To return\n");
    scanf("%d", &chtm3);
    switch(chtm3)
    {
        case 1:
        {
            a=1;
            
                if(t==1)
                {
                    printf("***Mumbai City FC***\n");
                }
                else if(t==2)
                {
                    printf("***Jamshedpur FC***\n");
                }
                else
                {
                    printf("***ATK FC***\n");
                }
            	
            sort(start, a);
            break;
        }
        case 2:
        {
            a=1;
            
                if(t==1)
                {
                    printf("***Mumbai City FC***\n");
                }
                else if(t==2)
                {
                    printf("***Jamshedpur FC***\n");
                }
                else
                {
                    printf("***ATK FC***\n");
                }
            sort(start, a);
            break;
        }
        case 3:
        {
            a=2;
            
                if(t==1)
                {
                    printf("***Mumbai City FC***\n");
                }
                else if(t==2)
                {
                    printf("***Jamshedpur FC***\n");
                }
                else
                {
                    printf("***ATK FC***\n");
                }
            sort(start, a);
            break;
        }
        case 4:
        {
            a=3;
            
                if(t==1)
                {
                    printf("***Mumbai City FC***\n");
                }
                else if(t==2)
                {
                    printf("***Jamshedpur FC***\n");
                }
                else
                {
                    printf("***ATK FC***\n");
                }
            sort(start, a);
            break;
        }
        case 5:
        {
            a=4;
            
                if(t==1)
                {
                    printf("***Mumbai City FC***\n");
                }
                else if(t==2)
                {
                    printf("***Jamshedpur FC***\n");
                }
                else
                {
                    printf("***ATK FC***\n");
                }
            sort(start, a);
            break;
        }
        case 6:
        {
            a=5;
            
                if(t==1)
                {
                    printf("***Mumbai City FC***\n");
                }
                else if(t==2)
                {
                    printf("***Jamshedpur FC***\n");
                }
                else
                {
                    printf("***ATK FC***\n");
                }
            sort(start, a);
            break;
        }
        case 7:
        {
            a=6;
            
                if(t==1)
                {
                    printf("***Mumbai City FC***\n");
                }
                else if(t==2)
                {
                    printf("***Jamshedpur FC***\n");
                }
                else
                {
                    printf("***ATK FC***\n");
                }
            sort(start, a);
            break;
        }
        case 8:
        {
            a=7;
            
                if(t==1)
                {
                    printf("***Mumbai City FC***\n");
                }
                else if(t==2)
                {
                    printf("***Jamshedpur FC***\n");
                }
                else
                {
                    printf("***ATK FC***\n");
                }
            sort(start, a);
            break;
        }
        case 9:
        {
            break;
        }
        default:
        {
            printf("Please enter a valid choice\n");
        }
    }
}


plr *team1(plr *start, int t)
{
        int chtm2, i=0;
        printf("Select\n");
        printf("1. To add a player\n");
        printf("2. To read database\n");
        printf("3. To return\n");
        scanf("%d", &chtm2);
        switch(chtm2)
        {
            case 1:
            {
                if(t==1)
                {
                    printf("***Mumbai City FC***\n");
                }
                else if(t==2)
                {
                    printf("***Jamshedpur FC***\n");
                }
                else
                {
                    printf("***ATK FC***\n");
                }
                start=read(start);
                i++;
                break;
            }
            
            case 2:
            {
                if(t==1)
                {
                    printf("***Mumbai City FC***\n");
                }
                else if(t==2)
                {
                    printf("***Jamshedpur FC***\n");
                }
                else
                {
                    printf("***ATK FC***\n");
                }
                start=team(start,t);
                break;
            }
            
            case 3:
            {
                return start;
            }
            default: printf("Please select a valid number\n");
        }
        return start;
}


void main()
{
	struct node n[100];
    int chplr,chtm, i=0;
    plr *mum, *jam, *atk;
    mum=NULL;
    jam=NULL;
    atk=NULL;
    do
    {
        printf("Select team\n");
        printf("1. Mumbai City FC\n");
        printf("2. Jamshedpur FC\n");
        printf("3. ATK FC\n");
        printf("4. To exit\n");
        scanf("%d", &chtm);
        switch(chtm)
        {
            case 1:
            {
                mum=team1(mum, chtm);
                break;
            }
            
            case 2:
            {
                jam=team1(jam, chtm);
                break;
            }
            
            case 3:
            {
                atk=team1(atk, chtm);
                break;
            }
            
            case 4:
            {
                printf("Thank you for accessing our player database!!\n");
                break;
            }
            
            default: printf("Please select a valid number\n");
        }
    }while(chtm!=4);
}

/*
 Enter:
 1. To read data
 2. To print
 3. To sort by name
 4. To sort by number of goals scored
 5. To sort by number of assists
 6. To sort by player overall
 7. To sort by current market value
 8. To exit
 1
 warning: this program uses gets(), which is unsafe.
 Enter name of player:
 A
 Enter number of goals scored:
 1
 Enter number of assists given:
 3
 Enter player overall rating:
 2
 Enter current market value of player(in mn pounds)
 4
 Enter:
 1. To read data
 2. To print
 3. To sort by name
 4. To sort by number of goals scored
 5. To sort by number of assists
 6. To sort by player overall
 7. To sort by current market value
 8. To exit
 1
 Enter name of player:
 AA
 Enter number of goals scored:
 1
 Enter number of assists given:
 3
 Enter player overall rating:
 2
 Enter current market value of player(in mn pounds)
 4
 Enter:
 1. To read data
 2. To print
 3. To sort by name
 4. To sort by number of goals scored
 5. To sort by number of assists
 6. To sort by player overall
 7. To sort by current market value
 8. To exit
 1
 Enter name of player:
 AB
 Enter number of goals scored:
 4
 Enter number of assists given:
 1
 Enter player overall rating:
 32
 Enter current market value of player(in mn pounds)
 2
 Enter:
 1. To read data
 2. To print
 3. To sort by name
 4. To sort by number of goals scored
 5. To sort by number of assists
 6. To sort by player overall
 7. To sort by current market value
 8. To exit
 3
 Name | Goals | Assists | Overall | Value
 A | 1 | 3 | 2 | 4.000000
 -----------------------
 AA | 1 | 3 | 2 | 4.000000
 -----------------------
 AB | 4 | 1 | 32 | 2.000000
 -----------------------
 Enter:
 1. To read data
 2. To print
 3. To sort by name
 4. To sort by number of goals scored
 5. To sort by number of assists
 6. To sort by player overall
 7. To sort by current market value
 8. To exit
 3
 Name | Goals | Assists | Overall | Value
 A | 1 | 3 | 2 | 4.000000
 -----------------------
 AA | 1 | 3 | 2 | 4.000000
 -----------------------
 AB | 4 | 1 | 32 | 2.000000
 -----------------------
 Enter:
 1. To read data
 2. To print
 3. To sort by name
 4. To sort by number of goals scored
 5. To sort by number of assists
 6. To sort by player overall
 7. To sort by current market value
 8. To exit
 4
 Name | Goals | Assists | Overall | Value
 AB | 4 | 1 | 32 | 2.000000
 -----------------------
 A | 1 | 3 | 2 | 4.000000
 -----------------------
 AA | 1 | 3 | 2 | 4.000000
 -----------------------
 Enter:
 1. To read data
 2. To print
 3. To sort by name
 4. To sort by number of goals scored
 5. To sort by number of assists
 6. To sort by player overall
 7. To sort by current market value
 8. To exit
 5
 Name | Goals | Assists | Overall | Value
 A | 1 | 3 | 2 | 4.000000
 -----------------------
 AA | 1 | 3 | 2 | 4.000000
 -----------------------
 AB | 4 | 1 | 32 | 2.000000
 -----------------------
 Enter:
 1. To read data
 2. To print
 3. To sort by name
 4. To sort by number of goals scored
 5. To sort by number of assists
 6. To sort by player overall
 7. To sort by current market value
 8. To exit
 6
 Name | Goals | Assists | Overall | Value
 AB | 4 | 1 | 32 | 2.000000
 -----------------------
 A | 1 | 3 | 2 | 4.000000
 -----------------------
 AA | 1 | 3 | 2 | 4.000000
 -----------------------
 Enter:
 1. To read data
 2. To print
 3. To sort by name
 4. To sort by number of goals scored
 5. To sort by number of assists
 6. To sort by player overall
 7. To sort by current market value
 8. To exit
 7
 Name | Goals | Assists | Overall | Value
 A | 1 | 3 | 2 | 4.000000
 -----------------------
 AA | 1 | 3 | 2 | 4.000000
 -----------------------
 AB | 4 | 1 | 32 | 2.000000
 -----------------------
 Enter:
 1. To read data
 2. To print
 3. To sort by name
 4. To sort by number of goals scored
 5. To sort by number of assists
 6. To sort by player overall
 7. To sort by current market value
 8. To exit
 8
 Players in your database are
 Name | Goals | Assists | Overall | Value
 A | 1 | 3 | 2 | 4.000000
 -----------------------
 AA | 1 | 3 | 2 | 4.000000
 -----------------------
 AB | 4 | 1 | 32 | 2.000000
*/

