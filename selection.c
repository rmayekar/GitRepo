#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void selection_sort(int [],int);

int main(int argc, char **argv[])
{
	int a[10000],n,i,j;
	double start,end;
	struct timeval tv;

	do
	{
		printf("\nEnter the size of the array: ");
		scanf("%d",&n);
		
		srand(time(NULL));
		for(i=0;i<n;i++)
		{
			a[i]=rand()%10000;
		}

		printf("\nThe unsorted random numbers are:\n\n");
	
		for(i=0;i<n;i++)
		{
			printf("%d\t",a[i]);
		}
		
		gettimeofday(&tv,NULL);
		start = tv.tv_sec + (tv.tv_usec/1000000.0);
	
		selection_sort(a,n);
	
		gettimeofday(&tv,NULL);
		end = tv.tv_sec + (tv.tv_usec/1000000.0);
	
		printf("\n\nThe array elements after sorting are:\n\n");		
		for(i=0;i<n;i++)
		{
			printf("%d\t",a[i]);
		}

		printf("\n\nThe Elapsed time: %lf sec\n",(end-start)*1000000);

		printf("\nPress 1. to retray or press any key to exit: ");
		scanf("%d",&j);

		printf("\n");
	}while(j==1);
	
	return 0;
}

void selection_sort(int a[],int n)
{
	int temp,i,j,min;

	for(i=0;i<(n-1);i++)
	{
		min=i;

		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
			{
				min=j;
			}
		}
		temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	}
}
