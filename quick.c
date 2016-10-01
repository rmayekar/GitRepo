#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void quick_sort(int [],int,int);
int partition(int [],int,int);

int main(int argc,char **argv[])
{
	int i,j,size,a[10000];
	double start,end;
	struct timeval tv;

	do
	{
		printf("\nEnter the array size: ");
		scanf("%d",&size);

		srand(time(NULL));
		for(i=0;i<size;i++)
		{
			a[i]=rand()%10000;
		}

		printf("\nThe unsorted random numbers are:\n\n");
		for(i=0;i<size;i++)
		{
			printf("%d\t",a[i]);
		}

		gettimeofday(&tv,NULL);
		start = tv.tv_sec + (tv.tv_usec/1000000.0);

		quick_sort(a,0,size-1);

		gettimeofday(&tv,NULL);
		end = tv.tv_sec + (tv.tv_usec/1000000.0);
	
		printf("\n\nThe sorted array is:\n\n");
		for(i=0;i<size;i++)
		{
			printf("%d\t",a[i]);
		}
		printf("\n");
		
		printf("\nThe elapsed time: %lf\n",(end-start)*1000000);

		printf("\nPress 1. to retray or press any key to exit: ");
		scanf("%d",&j);
	}while(j==1);		

	return 0;
}

void quick_sort(int a[],int low,int high)
{
	int j;

	if(low<high)
	{
		j = partition(a,low,high);
		quick_sort(a,low,j-1);
		quick_sort(a,j+1,high);
	}
}

int partition(int a[],int low,int high)
{
	int key,temp,i,j;

	key = a[low];
	i = low+1;
	j = high;

	while(1)
	{
		while(a[i]<=key && i<high)
		{
			i++;
		}

		while(a[j]>=key && j>low)
		{
			--j;
		}
		
		if(i<j)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
		else
		{
			temp = a[low];
			a[low] = a[j];
			a[j] = temp;

			return j;
		}
	}
}
