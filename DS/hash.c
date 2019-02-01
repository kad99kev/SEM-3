/*
 Title   : Implementation of hashing
 Name    : Kevlyn Kadamala
 Roll no.: 8340
 */

#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

int linprobe(int arr[], int key, int end)
{
	int k;
	k=key%end;
	if(arr[k]!=0)
	{
		k=linprobe(arr, key+1, end);
		return k;
	}
	return k;
	
}

int linprobesearch(int arr[], int key, int end)
{
    int k, i, c;
    c=key;
    k=key%end;
    for(i=0; i<end; i++, c++)
    {
        k=c%end;
        if(arr[k]==key)
        {
            return k;
        }
    }
    printf("Element not found\n");
    return -1;
}

int quadprobesearch(int arr[], int key, int end)
{
    int k, i, c;
    c=key;
    for(i=0; i<end; i++, c++)
    {
        k=(key+i*i)%end;
        if(arr[k]==key)
        {
            return k;
        }
    }
    printf("Element not found\n");
    return -1;
}

int quadprobe(int arr[], int key, int pow, int end)
{
    int k, i=pow;
    k=(key+i*i)%end;
    if(arr[k]!=0)
    {
        k=quadprobe(arr, key, i+1, end);
        return k;
    }
    return k;
}


void display(int list[], int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		if(list[i]!=0)
		{
			printf("%d ", list[i]);
		}
	}
	printf("\n");
}

void main()
{
	int n, i, ele, k, key, choice;
	printf("Enter size of array\n");
	scanf("%d", &n);
	int hash[SIZE]={0};
    
    printf("Enter 1 for linear probing OR 2 for quadradic probing\n");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
        {
            printf("Enter elements (Enter -1 to stop)\n");
            for(i=0; i<n; i++)
            {
                scanf("%d", &ele);
                if(ele==-1)
                {
                    break;
                }
                k=linprobe(hash, ele, n);
                hash[k]=ele;
            }
            printf("Elements are\n");
            display(hash ,n);
            printf("Enter element to be searched\n");
            scanf("%d", &ele);
            key=linprobesearch(hash, ele, n);
            if(key!=-1)
            {
                printf("Element %d is at %d index\n", ele, key);
            }
        }
        break;
        case 2:
        {
            printf("Enter elements (Enter -1 to stop)\n");
            for(i=0; i<n; i++)
            {
                scanf("%d", &ele);
                if(ele==-1)
                {
                    break;
                }
                k=quadprobe(hash, ele, 0, n);
                hash[k]=ele;
            }
            printf("Elements are\n");
            display(hash ,n);
            printf("Enter element to be searched\n");
            scanf("%d", &ele);
            key=quadprobesearch(hash, ele, n);
            if(key!=-1)
            {
                printf("Element %d is at %d index\n", ele, key);
            }
        }
        break;
        default:
        {
            printf("Invalid choice\n");
        }
    }

	
}

/*
 Enter size of array
 10
 Enter 1 for linear probing OR 2 for quadradic probing
 1
 Enter elements (Enter -1 to stop)
 70
 55
 53
 75
 81
 63
 90
 92
 -1
 Elements are
 70 81 90 53 63 55 75 92
 Enter element to be searched
 53
 Element 53 is at 3 index

 Enter size of array
 10
 Enter 1 for linear probing OR 2 for quadradic probing
 2
 Enter elements (Enter -1 to stop)
 70
 55
 53
 75
 81
 63
 90
 92
 -1
 Elements are
 70 92 75 81 55 53 63 90
 Enter element to be searched
 53
 Element 53 is at 7 index
 
 Enter size of array
 10
 Enter 1 for linear probing OR 2 for quadradic probing
 1
 Enter elements (Enter -1 to stop)
 70
 55
 53
 75
 81
 63
 90
 92
 -1
 Elements are
 70 81 90 53 63 55 75 92
 Enter element to be searched
 10
 Element not found
*/
