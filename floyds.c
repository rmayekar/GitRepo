#include<stdio.h>

void floyds(int c[][10], int n);
int min(int, int);

int main(int argc, char **argv[])
{
	int i,j,n,c[10][10],key;

	do{
		printf("\nEnter the number of vertices: ");
		scanf("%d",&n);	

		printf("\nEnter the cost matrix:\n\n");
		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
				scanf("%d",&c[i][j]);

		printf("\n\nThe entered cost matrix is:\n\n");
		for(i = 1; i <= n; i++){
			for(j = 1; j <= n; j++)
				printf("%d\t",c[i][j]);

			printf("\n\n");
		}

		floyds(c,n);

		printf("\n\nThe All Pair Shortest Path Matrix is:\n\n");
		for(i = 1; i <= n; i++){
			for(j = 1; j <= n; j++)
				printf("%d\t",c[i][j]);

			printf("\n\n");
		}
	
		printf("\n\nPress 1. to Retry or press any key to exit: ");
		scanf("%d",&key);
	}while(key == 1);
	
	return 0;
}

void floyds(int c[][10], int n)
{
	int i,j,k;

	for(k = 1; k <= n; k++)
		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
				c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
}

int min(int x, int y)
{
	if(x > y)	
		return y;
	else
		return x;
}

/* Output

Enter the number of vertices: 4

Enter the cost matrix:

0 9999 3 9999
2 0 9999 9999
9999 6 0 1
7 9999 9999 0


The entered cost matrix is:

0	9999	3	9999	

2	0	9999	9999	

9999	6	0	1	

7	9999	9999	0	



The All Pair Shortest Path Matrix is:

0	9	3	4	

2	0	5	6	

8	6	0	1	

7	16	10	0	
*/
