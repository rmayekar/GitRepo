#include<stdio.h>
#include<time.h>
#include<stdlib.h>


void heapify(int [], int);
void heap_sort(int [], int);


int main()
{
	int size,choice,a[10000],i,j,key;


	do
	{
		printf("\nPress 1. to enter the user elements");
		printf("\nPress 2. for random elements");
		printf("\nPress any to Exit\n");

		printf("\nEnter your choice: ");
		scanf("%d",&choice);

		if(choice == 1 || choice == 2 )
		{
			printf("\nEnter the size of the array to be sorted: ");
			scanf("%d",&size);
		}

		switch(choice)
		{
			case 1: printf("\nEnter the elements to be sorted:\n");
				for(i = 1; i <= size; i++)
					scanf("%d",&a[i]);

				printf("\nThe elements to be sorted are:\n");
				for(i = 1; i <= size; i++)
					printf("%d\t",a[i]);

				heap_sort(a,size);

				break;

			case 2:  srand(time(NULL)); 
				for(i = 1; i <= size; i++)
					a[i] = rand()%10000;

				printf("\nThe elements to be sorted are:\n");
				for(i = 0; i< size; i++)
					printf("%d\t",a[i]);

				heap_sort(a,size);

				break;

			default:exit(0);
		}

		printf("\n\nThe sorted elements are:\n");
		for(i = 1;i <= size; i++)
			printf("%d\t",a[i]);

		printf("\n\nPress 1. to Retry or press any key to exit: ");
		scanf("%d",&key);
	}while(key == 1);

		return 0;
}


void heap_sort(int a[], int n)
{
	int temp;

	while(n>1)
	{
		heapify(a,n);

		temp = a[1];
		a[1] = a[n];
		a[n] = temp;

		n--;
	}
}



void heapify(int a[], int n)
{
	int i,j,k,v,heap;

	for(i = n/2; i > 0; i--)
	{
		k = i;
		v = a[i];
		heap = 0;

			while(!heap && (2*k) <= n)
			{
				j = 2*k;
				if(j < n)
				{
					if(a[j] < a[j+1])
						j = j+1;
				}

				if(v >= a[j])
					heap = 1;
				else
				{
					a[k] = a[j];
					k = j;
				}
			}
		a[k] = v;
	}
}



