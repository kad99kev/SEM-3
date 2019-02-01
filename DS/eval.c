/*
 Title   : Evaluation of postfix
 Name    : Kevlyn Kadamala
 Roll no.: 8340
 */

#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

typedef struct stack     //Stack declaration
{
 int a[SIZE], top;
}stk;

void init_stack(stk *p) //Stack initialization function
{
 p->top=-1;
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

void push(stk *p, int x)    //To push values into stack
{
 if(isfull(p->top))
  {
    printf("Stack overflow\n");
  }
 else
  {
   p->a[++p->top]=x;
  }
}

int pop(stk *p)     //To pop values out of stack
{
 int x;
 if(isempty(p->top))
  {
   printf("Stack underflow\n");
   exit(0);
  }
 else
  {
   x=p->a[p->top];
   p->top--;
   return x;
  }
}



int isOperand(char x)   //To check if entered character is operand
{
  if(x>='0' && x<='9')
	return 1;
  else
	return 0;
}

void operate(stk *p, int a, int b, char o)      //To perform desired operation
{
 int n;
 switch(o)
	{
	  case '+': n=a+b;
		break;
	  case '-': n=a-b;
		break;
	  case '*': n=a*b;
		break;
	  case '/': n=a/b;
		break;
	  case '%': n=a%b;
          	break;
	}

	push(p,n);
}


void main()
{
  stk s;
  init_stack(&s);
  char exp[50], *p;
  int op1, op2, val, i, x;
  printf("Enter postfix expression\n");
  gets(exp);
  for(p=exp; *p!='\0'; p++)
  {
    if(isOperand(*p))
      push(&s, *p-'0');
    else
    {
        op2=pop(&s);
        op1=pop(&s);
        operate(&s,op1,op2,*p);
    }
  }
x=pop(&s);
printf("%d\n", x);
  
}

/* Enter postfix expression
 23*45++
 15 */
