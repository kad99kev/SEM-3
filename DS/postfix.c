/*
 Title   : Conversion of an expresiion from infix to postfix (reverse polish notation)
 Name    : Kevlyn Kadamala
 Roll no.: 8340
 */

#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

typedef struct stack    //Stack declaration
{
    char a[SIZE], top;
}stk;

void init_stack(stk *p) //Stack initialization function
{
    (*p).top=-1;
}

int isfull(int p)   //To check if stack is full
{
    if(p==SIZE-1)
        return 1;
    else
        return 0;
}

int isempty(int p)  //To check if stack is empty
{
    if(p==-1)
        return 1;
    else
        return 0;
}

void push(stk *p, char x)   //To push values into stack
{
    if(isfull((*p).top))
    {
        printf("Stack overflow\n");
    }
    else
    {
        (*p).a[++(*p).top]=x;
    }
}

char pop(stk *p)    //To pop values out of stack
{
    char x;
    if(isempty((*p).top))
    {
        printf("Stack underflow\n");
        exit(0);
    }
    else
    {
        x=(*p).a[(*p).top];
        (*p).top--;
        return x;
    }
}


int top(stk *p)  //To check topmost value in the stack
{
    return (*p).a[(*p).top];
} 


int isOperand(char x) //To check if entered character is operand
{
    if((x>='0' && x<='9')||(x>='A' && x<='Z'))
        return 1;
    else
        return 0;
}

int precedence(char x)  //To check precendence of entered operators
{
    if(x=='(')
        return 0;
    if(x=='+'||x=='-')
        return 1;
    if(x=='*'||x=='/'||x=='%')
        return 2;
    return 3;
}

void display(stk *p)    //To display contents of stack
{
    int i;
    for(i=(*p).top; i>=0; i--)
        printf("%d\n", (*p).a[i]);
}  

void convert(char inf[])    //Function for infix conversion to postfix
{
    stk s;
    char post[50];
    init_stack(&s);
    char *p, x;
    int j=0;

    for(p=inf;*p!='\0'; p++)
    {
        if(isOperand(*p))   //Condition to check for operand
            post[j++]=*p;
        else if(*p=='(')    //Condition to check for opening parenthesis
            push(&s,*p);
        else if(*p==')')    //Condition to check for closing parenthesis
        {
            while(s.a[s.top]!='(')
            {
                x=pop(&s);
                post[j++]=x;
            }
            s.top--;
        }
        else
        {
            while( (precedence(*p)<=precedence(top(&s))) && !isempty(s.top) )   //To check for precendence
                /*Lower precedence cannot be above higher precedence in the stack*/
            {
                x=pop(&s);
                post[j++]=x;
            }
            push(&s,*p);
        }
    }

    while(!isempty(s.top))
    {
        x=pop(&s);
        post[j++]=x;
    }
  
    post[j]='\0';
    
    printf("Postfix experssion is\n");
  
    printf("%s\n", post);
 
}


void main()
{
    char infix[50];
    printf("Enter infix expression\n");
    gets(infix);
    convert(infix);
  
}

/* Enter infix expression
 A*(B+C)
 Postfix experssion is
 ABC+*  */
