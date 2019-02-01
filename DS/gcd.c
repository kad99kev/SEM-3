//
//  gcd.c
//  
//
//  Created by Kevlyn Kadamala on 15/12/18.
//

#include <stdio.h>
#include<stdlib.h>

int gcdrec(int a, int b){
    if(b == 0){
        return a;
    }
    else{
        return gcdrec(b, a%b);
    }
}

int gcd(int a, int b){
    int temp;
    while(b != 0){
        temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

void main(){
    int m, n;
    printf("Enter two numbers\n");
    scanf("%d%d", &m, &n);
    printf("GCD using recursion is %d\n", gcdrec(m, n));
    printf("GCD without using recursion is %d\n", gcd(m, n));
}
