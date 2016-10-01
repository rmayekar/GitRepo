/* Header files in C library */
#include<stdio.h>

/* Function Prototypes */
int binomial_coefficient(int,int);

/* Function main() begins program excution and returns an integer value to the operating system */
int main(int argc, char **argv[])
{
	int n,r,i,ans;

	do{
		printf("\nEnter the the value of n: ");
		scanf("%d",&n);

		printf("\nEnter the value of r: ");
		scanf("%d",&r);

		/* Calls the function binomial_coefficient() to generate the combinations */
		ans = binomial_coefficient(n,r);
		printf("\nThe answer is: %d\n",ans);

		printf("\nPress 1. to Retray or press any key to Exit: ");
		scanf("%d",&i);
	}while(i == 1);

	return 0;  /* Incidate successful termination */
}

int binomial_coefficient(int n,int r)
{
	int i,j,c[10][10];
	
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=r;j++)
		{
			if(j == 0 || j == i)
			{
				c[i][j] = 1;
			}
			else
			{
				c[i][j] = c[i-1][j] + c[i-1][j-1];
			}
		}
	}
	return c[n][r];
}

/* Output

Enter the the value of n: 10

Enter the value of r: 3

The answer is: 120
*/

