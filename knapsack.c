/* Header files in C library */
#include<stdio.h>

/* Function Prototypes */
int knapsack(int,int [],int [],int);
int max(int,int);

/* Function main() begins program excution and returns an integer value to the operating system */
int main(int argc,char **argv[])
{
	int n,w[10],p[10],m,i,ans,key;
	
	do{
		printf("\nEnter the number of items: ");
		scanf("%d",&n);

		printf("\nEnter the weight of %d items\n",n);
		for(i = 1;i <= n;i++)
		{
			scanf("%d",&w[i]);
		}

		printf("\nEnter the values of %d items\n",n);
		for(i = 1;i <= n;i++)
		{
			scanf("%d",&p[i]);
		}

		printf("\nEnter the kanpsack capacity: ");
		scanf("%d",&m);
		
		/* Calls the function kanpsack() */
		ans = kanpsack(n,w,p,m);

		printf("\nThe optimal solution is: %d\n",ans);

		printf("\nPress 1. to retray or press any key to exit: ");
		scanf("%d",&key);
	}while(key == 1);

	return 0;  /* Incidate successful termination */
}

int kanpsack(int n,int w[],int p[],int m)
{
	int i,j,v[10][10];

	for(i =0;i <= n;i++)
	{
		for(j = 0;j <= m;j++)
		{
			if(i == 0 || j == 0)
			{
				v[i][j] = 0;
			}
			else if(j-w[i] < 0)
			{
				v[i][j] = v[i-1][j];
			}
			else
			{
				v[i][j] = max(v[i-1][j], p[i]+v[i-1][j-w[i]]);
			}
		}
	}
	return v[n][m];
}

int max(int x,int y)
{
	if(x > y)
		return x;
	else 
		return y;
}

/* Output

Enter the number of items: 3

Enter the weight of 3 items
1
2
3

Enter the values of 3 items
18
16
6

Enter the kanpsack capacity: 4

The optimal solution is: 34
*/
