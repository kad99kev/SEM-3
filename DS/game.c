//
//  game.c
//  
//
//  Created by Kevlyn Kadamala on 18/09/18.
//

#include <stdio.h>
#include<stdlib.h>
#define SIZE 100

typedef struct node //Node Declaration
{
    char exp;
    struct node *next;
}nd;

nd *create(nd *START, char c) //To insert node at the end
{
    nd *p=(nd *)malloc(sizeof(nd));
    nd *ptr;
    p->exp=c;
    if(START==NULL)
    {
        START=p;
        p->next=NULL;
    }
    else
    {
        ptr=START;
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=p;
        p->next=NULL;
    }
    
    return START;
}

int verify(nd *START_ANS, nd *START_QUES)
{
    nd *ptr_ques, *ptr_ans;
    ptr_ques=START_QUES;
    ptr_ans=START_ANS;
    while(ptr_ques!=NULL && ptr_ans!=NULL)
    {
        if(ptr_ans->exp!=ptr_ques->exp)
        {
            return 0;
        }
        ptr_ques=ptr_ques->next;
        ptr_ans=ptr_ans->next;
    }
    return 1;
}

nd *answer_Update(nd *START_QUES,nd *START_ANS, char key)
{
    nd *ptr_ques, *ptr_ans;
    ptr_ques=START_QUES;
    ptr_ans=START_ANS;
    while(ptr_ques!=NULL && ptr_ans!=NULL)
    {
        if(ptr_ques->exp==key)
        {
            ptr_ans->exp=key;
        }
        ptr_ques=ptr_ques->next;
        ptr_ans=ptr_ans->next;
    }
    return START_ANS;
}

void answer_Display(nd *START_ANS)
{
    nd *ptr;
    ptr=START_ANS;
    if(START_ANS==NULL)
        printf("List is empty\n");
    else
    {
        while(ptr!=NULL)
        {
            printf("%c",ptr->exp);
            ptr=ptr->next;
        }
        printf("\n");
    }
}

void answer(nd *START_QUES, nd *START_ANS)
{
    int check=1, answer=0;
    char c;
    do
    {
        printf("Enter 1 to continue, 0 to give up\n");
        scanf("%d", &check);
        if(check==0)
        {
            break;
        }
        else
        {
            printf("Enter an alphabet\n");
            scanf("%c", &c);
            scanf("%c", &c);
            START_ANS=answer_Update(START_QUES, START_ANS, c);
            answer_Display(START_ANS);
            answer=verify(START_ANS, START_QUES);
        }
    }while(check!=0 && answer!=1);
    if(check==0)
    {
        printf("Aww so sad xD\n");
    }
    if(answer==1)
    {
        printf("Yay you guessed right!\n");
    }
}

void read_exp(char ques[])
{
    nd *START_QUES=(nd *)malloc(sizeof(nd));
    nd *START_ANS=(nd *)malloc(sizeof(nd));
    int i;
    for(i=0; ques[i]!='\0'; i++)
    {
        START_QUES=create(START_QUES, ques[i]);
        START_ANS=create(START_ANS, '_');
    }
    answer(START_QUES, START_ANS);
}

void main()
{
    nd *QUES, *ANS;
    char ques[SIZE];
    printf("Enter word to be guessed (All in lower case please no cheating xD)\n");
    gets(ques);
    printf( "\033[2J" );
    read_exp(ques);
}
