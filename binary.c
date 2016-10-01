/*Header files in C library*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

/*Function Prototypes*/
int binary_search(int [],int,int,int);
void selection_sort(int [],int);

/*Function main() begins program excution and returns an integer value to the operating system*/
int main(int argc, char **argv[])
{
	int a[10000],ans,size,i,j,key;
	double start,end;
	struct timeval tv;

	do
	{
		printf("\nEnter the size of the array: ");
		scanf("%d",&size);
		
		/*to generate random numbers */
		srand(time(NULL));
		for(i=0;i<size;i++)
		{
			a[i]=rand()%10000;
		}
		
		/*Call selection_sort() function*/
		selection_sort(a,size);

		printf("\nThe sorted array elements are:\n\n");
		for(i=0;i<size;i++)
		{
			printf("%d\t",a[i]);
		}
		
		printf("\nEnter the search key: ");
		scanf("%d",&key);

		/* gets the time at the beginning of the program */
		gettimeofday(&tv,NULL);
		start = tv.tv_sec + (tv.tv_usec/1000000.0);
		
		/*calls binary_search() function and stores the return value in 'ans'*/
		ans = binary_search(a,key,0,(size-1));

		/* gets the time at the end of the program */
		gettimeofday(&tv,NULL);
		end = tv.tv_sec + (tv.tv_usec/1000000.0);

		if(ans==-1)
		{
			printf("\nSearch Unsuccessful");
			printf("\nSearch key not found\n");
		}
		else
		{
			printf("\nSearch Successul");
			printf("\nSearch key %d is found in %d position\n",key,(ans+1));
		}

		printf("\nElapsed Time: %lf\n",(end-start)*1000000);

		printf("\n\nPress 1. to retray or press any key to exit: ");
		scanf("%d",&j);
	}while(j==1);

	return 0;/*incidate successful termination*/
}

/* binary_search() function definition */
int binary_search(int a[],int key,int low,int high)
{
	int mid;

	if(low<=high)
	{
		mid = (low + high)/2;

		if(key==a[mid])
		{
			return mid;
		}
		else if(key<a[mid])
		{
			return binary_search(a,key,0,(mid-1));
		}
		else 
		{
			return binary_search(a,key,(mid+1),high);
		}
	}
	
	return -1;
}

/*selection_sort() function */
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


