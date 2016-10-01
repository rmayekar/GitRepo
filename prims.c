#include<stdio.h>

void prims(int c[][10], int n);

int main(int argc, char **argv[])
{
	int c[10][10],n;
	int i,j,key;

	do{
		printf("\nEnter the number of vertices: ");
		scanf("%d",&n);

		printf("\nEnter the cost matrix:\n\n");
		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
				scanf("%d",&c[i][j]);

		prims(c,n);
		
		printf("\n\nPress 1. to Retry or press any key to exit: ");
		scanf("%d",&key);
	}while(key == 1);
	return 0;
}
	
void prims(int c[][10], int n)
{
	int u,v;
	int min,mincost,ne,elec[10];
	int i,j;

	mincost = 0;
	ne = 0;

	for(i = 1; i <= n; i++)
		elec[i] = 0;

	elec[1] = 1;

	while(ne != n-1){
		min = 9999;
		
		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
				if(elec[i] == 1){
					if(c[i][j] < min){
						min = c[i][j];
						u = i;
						v = j;
					}
				}

		if(elec[v] != 1){
			printf("\n%d ----------> %d = %d",u,v,min);
			elec[v] = 1;
			ne = ne + 1;
			mincost = mincost + min;
		}
		
		c[u][v] = c[v][u] = 9999;
	}
	
	printf("\nThe Minimum Cost of the spanning tree is: %d\n",mincost);
}

/* Output

Enter the number of vertices: 5

Enter the cost matrix:

9999 5 2 7 9999
5 9999 3 9999 6
2 3 9999 4 5
7 9999 4 9999 7
9999 6 5 7 9999

1 ----------> 3 = 2
3 ----------> 2 = 3
3 ----------> 4 = 4
3 ----------> 5 = 5
The Minimum Cost of the spanning tree is: 14
*/
