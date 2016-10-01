/*heder files in C library */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*function prototypes */
void split(int [],int,int);
void combine(int [],int,int,int);

/*Function main() begins program excution and returns an integer value to the operating system*/
int main(int argc,char **argv[])
{
	int a[10000],i,j,n;
	double start,end;
	struct timeval tv;

	printf("\nEnter the size of the array: ");
	scanf("%d",&n);

	/*to generate random numbers */
	srand(time(NULL));
	for(i=0;i<n;i++)
	{
		a[i]=rand()%10000;
	}

	printf("\nThe unsorted array is:\n\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	
	/* gets the time at the beginning of the program */
	gettimeofday(&tv,NULL);
	start = tv.tv_sec + (tv.tv_usec/1000000.0);
	
	/* calls split() function */
	split(a,0,(n-1));

	/* gets the time at the end of the program */
	gettimeofday(&tv,NULL);
	end = tv.tv_sec + (tv.tv_usec/1000000.0);

	printf("\nThe sorted array is:\n\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
		
	printf("\nThe elapsed time: %lf seconds\n\n",(end-start)*1000000);

	return 0;/*incidate successful termination*/
}

/* split() function definition */
void split(int a[],int low,int high)
{
	int mid;
	
	if(low<high)
	{
		mid=(low+high)/2;
		split(a,low,mid);
		split(a,mid+1,high);
		combine(a,low,mid,high);/*calls combine() function */
	}
}

/* combine() function definition */
void combine(int a[], int low, int mid, int high)
{
	int i,j,k,n;
	int c[10000];

	i=low;
	j=mid+1;
	k=low;

	while(i<=mid && j<=high)
	{
		if(a[i]<=a[j])
		{
			c[k]=a[i];
			k++;
			i++;
		}
		else
		{
			c[k]=a[j];
			k++;
			j++;
		}
	}
	
	if(i>mid)
	{
		while(j<=high)
		{
			c[k]=a[j];
			k++;
			j++;
		}
	}
	else
	{
		while(i<=mid)
		{
			c[k]=a[i];
			k++;
			i++;
		}
	}

	for(n=low;n<=high;n++)
	{
		a[n]=c[n];
	}
}

