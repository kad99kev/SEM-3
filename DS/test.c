//
//  test.c
//  
//
//  Created by Kevlyn Kadamala on 16/09/18.
//

#include <stdio.h>


int test(int x)
{
    if(x==1)
    {
        return x*1241;
    }
    else
    {
     return test(--x);
    }
}

void main()
{
    int a;
    a=test(213);
    printf("%d\n", a);
}
