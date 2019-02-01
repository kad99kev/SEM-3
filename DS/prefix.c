/*
 Title   : Conversion of an expression from infix to prefix (Polish notation)
 Name    : Kevlyn Kadamala
 Roll no.: 8340
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

void convert(char inf[])    //Function for expression conversion to postfix
{
    stk s;
    char pre[50], final[50];
    init_stack(&s);
    char *p, x;
    int j=0,len, i;
    
    for(p=inf;*p!='\0'; p++)
    {
        if(isOperand(*p))   //Condition to check for operand
            pre[j++]=*p;
        else if(*p=='(')    //Condition to check for opening parenthesis
            push(&s,*p);
        else if(*p==')')    //Condition to check for closing parenthesis
        {
            while(s.a[s.top]!='(')
            {
                x=pop(&s);
                pre[j++]=x;
            }
            s.top--;
        }
        else
        {
            while( (precedence(*p)<=precedence(top(&s))) && !isempty(s.top) )   //To check for precendence
            {
                x=pop(&s);
                pre[j++]=x;
            }
            push(&s,*p);
        }
    }
    
    while((s.a[s.top]!='(') && !isempty(s.top))
    {
        x=pop(&s);
        pre[j++]=x;
    }
    
    pre[j]='\0';
    
    len=strlen(pre);
    for(i=0; pre[i]!='\0'; i++) //To reverse expression
    {
        final[i]=pre[len-i-1];
    }
    final[i] = '\0';
    printf("Prefix expression is\n");
    
    
    printf("%s\n", final);
    
}


void main()
{
    char infix[50], t[50];
    int i=0, len=0;
    printf("Enter infix expression\n");
    gets(infix);
    len=strlen(infix);
    for(i=0; infix[i]!='\0'; i++) //To reverse expression
    {
        if(infix[len-1-i]=='(') // Parenthesis conversion
        {
            t[i]=')';
        }
        else if(infix[len-1-i]==')') // Parenthesis conversion
        {
            t[i]='(';
        }
        else
        {
            t[i]=infix[len-i-1];
        }
    }
    t[i]='\0';
    convert(t);
   
    
}

/*
 Enter infix expression
 (A+B)-(C*D)
 Prefix expression is
 -+AB*CD
 */
