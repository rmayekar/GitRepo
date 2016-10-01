#include<stdio.h>

void warshall(int c[][10], int n);

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

		warshall(c,n);

		printf("\n\nThe Transitive Closure Matrix is:\n\n");
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

void warshall(int c[][10], int n)
{
	int i,j,k;

	for(k = 1; k <= n; k++)
		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
				if(c[i][j] == 0)
					if(c[i][k] == 1 && c[k][j] == 1)
						c[i][j] = 1;
}

/* Output

Enter the number of vertices: 4

Enter the cost matrix:

0 1 0 0 
0 0 0 1
0 0 0 0
1 0 1 0


The entered cost matrix is:

0	1	0	0	

0	0	0	1	

0	0	0	0	

1	0	1	0	



The Transitive Closure Matrix is:

1	1	1	1	

1	1	1	1	

0	0	0	0	

1	1	1	1	
*/




