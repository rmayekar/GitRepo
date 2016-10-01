/*heder files in C library */
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

/*function prototypes */
int linear_search(int [],int,int,int);

/*Function main() begins program excution and returns an integer value to the operating system*/
int main(int argc, char **argv[])
{
	int a[10000],i,j,n,key,ans;
	double start,end;
	struct timeval tv;
	
	do
	{
		printf("\nEnter the size of the array: ");
		scanf("%d",&n);

		/*to generate random numbers */
		srand(time(NULL));
		for(i=0;i<n;i++)
		{
			a[i]=rand()%10000;
		}
	
		printf("\nThe %d random numbers are:\n\n",n);
		for(i=0;i<n;i++)
		{
			printf("%d\t",a[i]);
		}

		printf("\n\nEnter the search key: ");
		scanf("%d",&key);
		
		/* gets the time at the beginning of the program */
		gettimeofday(&tv,NULL);
		start = tv.tv_sec + (tv.tv_usec/1000000.0);

		/*calls linear_search() function and stores the return value in 'ans'*/
		ans = linear_search(a,key,0,n-1);

		/* gets the time at the end of the program */
		gettimeofday(&tv,NULL);
		end = tv.tv_sec + (tv.tv_usec/1000000.0);
	
		if(ans == -1)
		{
			printf("\nSearch Unsuccessful\n");
		}
		else
		{
			printf("\nSearch Successful\n");
			printf("\nKey found in %d position\n",ans+1);
		}
	
		printf("\nElapsed time: %lf sec\n",(end-start)*1000000.0);
		
		printf("\n\nPress 1. to retray or press any key to exit: ");
		scanf("%d",&j);
	}while(j==1);
	return 0;/*incidate successful termination*/
}

/* linear_search() function definition */
int linear_search(int a[],int key,int i,int high)
{
	if(i<=high)
	{
		if(key==a[i])
		{
			return i;
		}
		else
		{
			i++;
			return(linear_search(a,key,i,high));
		}
	}
	
	return -1;
}
		
