/*
Name: Kevlyn Kadamala
Topic: Implementation of Binary Search Method
Roll no: 8340
*/

#include<stdio.h>
#include<stdlib.h>

void main()
{
	int a[100];
	int mid,high,temp,low,i,j,n,x,flag=0;
	printf("Enter number of elements\n");
	scanf("%d",&n);
	printf("Enter elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++) //Bubble sort to sort array
	{
		for(j=0;j<n-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("Sorted array is\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
    printf("\n");
	low=0;
	high=n-1;
	mid=(n-1)/2;
	printf("Enter no to be searched\n");
	scanf("%d",&x);
	while(high>low) //To search element
	{	
		if(a[mid]==x)
		{
			flag=1;
			break;
		}
		else if(a[mid]>x) //If x is smaller
		{
			high=mid-1;
		}
		else //If x is higher
		{
			low=mid+1;
		}
        mid=(high+low)/2;
	}
	if(flag==1)
	{
		printf("%d is found at location %d\n",x,mid+1);
	}
	else
	{
		printf("Number not found\n");
	}
}

/*
 Enter number of elements
 6
 Enter elements
 2
 5
 6
 4
 3
 1
 Sorted array is
 1 2 3 4 5 6
 Enter no to be searched
 5
 5 is found at location 5

 Enter number of elements
 6
 Enter elements
 1
 5
 4
 2
 3
 6
 Sorted array is
 1 2 3 4 5 6
 Enter no to be searched
 7
 Number not found
*/
