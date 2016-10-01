#include<stdio.h>

int queen(int,int);
int place(int [],int);
void display(int [], int);

int main()
{
	int n,key,ans;
	
	do
	{
		printf("\nEnter the number of queen's: ");
		scanf("%d",&n);

		printf("\n");

		ans = queen(n,0);

		printf("The number of solutions for %d queens is: %d\n",n,ans);

		printf("\nPress 1. to Retry or press any key to exit: ");
		scanf("%d",&key);
	}while(key == 1);

	return 0;
}

int queen(int n,int count)
{
	int k,x[10];

	k = 1;
	x[k] = 0;

	while(k != 0)
	{
		x[k]++;

		while(place(x,k) != 1 && x[k] <= n)
		{
			x[k]++;
		}

		if(x[k] <= n)
		{
			if(k == n)
			{
				count++;
				display(x,n);
				printf("\n\n");
			}

			else
			{
				k++;
				x[k] = 0;
			}
		}

		else
		{
			k--;
		}
	}
	return count;
}

int place(int x[], int k)
{
	int i;

	for(i = 1; i <= k-1; i++)
	{
		if(i + x[i] == k + x[k] || i - x[i] == k - x[k] || x[i] == x[k])
		{
			return 0;
		}
	}

	return 1;
}

void display(int x[], int n)
{
	char chess[20][20];
	int i,j;

	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			chess[i][j] = '-';

	for(i = 1; i <= n; i++)
		chess[i][x[i]] = 'Q';

	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n; j++)
		{
			printf("%c",chess[i][j]);
		}
		printf("\n");
	}
}

/* Output

Enter the number of queen's: 4

-Q--
---Q
Q---
--Q-


--Q-
Q---
---Q
-Q--


The number of solutions for 4 queens is: 2
*/
