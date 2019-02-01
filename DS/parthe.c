//
//  parthe.c
//  
//
//  Created by Kevlyn Kadamala on 30/10/18.
//

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct stack
{
    char array[SIZE];
    int top;
}stk;

void init(stk *s)
{
    s->top = -1;
}

int isFull(int top)
{
    if(top == SIZE-1)
        return 1;
    else
        return 0;
}

int isEmpty(int top)
{
    if(top == -1)
        return 1;
    else
        return 0;
}

void push(stk *s, char c)
{
    if(isFull(s->top))
    {
        printf("Stack overflow\n");
    }
    else
    {
        s->array[++s->top] = c;
    }
}

char pop(stk *s)
{
    char c;
    if(isEmpty(s->top))
    {
        printf("Stack underflow\n");
    }
    else
    {
        c = s->array[s->top--];
    }
    return c;
}

void check(char exp[]){
    stk s;
    init(&s);
    int i, flag = 1;
    char *p, temp;
    for(p = exp; *p != '\0'; p++){
        if(*p == '(' || *p == '[' || *p == '{'){
            push(&s, *p);
        }
        if(*p == ')' || *p == ']' || *p == '}'){
            if(isEmpty(s.top)){
                flag = 0;
                break;
            }
            else{
                temp = pop(&s);
                if(!((temp == '(' && *p == ')') || (temp == '[' && *p == ']') || (temp == '{' && *p == '}'))){
                    flag = 0;
                }
            }
        }
    }
    if(!isEmpty(s.top) || flag == 0){
        printf("Parenthesis is not balanced\n");
    }
    else{
        printf("Parenthesis is balanced\n");
    }
}

int main(void)
{
    char exp[SIZE];
    printf("Enter expression\n");
    gets(exp);
    check(exp);
}
