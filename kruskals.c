#include<stdio.h>

void kruskals(int c[][10], int n);

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

		kruskals(c,n);
		
		printf("\n\nPress 1. to Retry or press any key to exit: ");
		scanf("%d",&key);
	}while(key == 1);
	return 0;
}
	
void kruskals(int c[][10], int  n)
{
	int a,b,u,v;
	int min,mincost,ne,parent[10];
	int i,j;

	mincost = 0;
	ne = 0;

	for(i = 1; i <= n; i++)
		parent[i] = 0;

	while(ne != n-1){
		min = 9999;
		
		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
				if(c[i][j] < min){
					min = c[i][j];
					a = u = i;
					b = v = j;
				}

		while(parent[u] != 0)
			u = parent[u];

		while(parent[v] != 0)
			v = parent[v];

		if(u != v){
			printf("\n%d ----------> %d = %d",a,b,min);
			parent[v] = u;
			mincost = mincost + min;
			ne = ne + 1;
		}

		c[a][b] = c[b][a] = 9999;
	}

	printf("\nThe Minimum Cost is: %d\n",mincost);
}

/* Output 

Enter the number of vertices: 5

Enter the cost matrix:

9999 5 9999 7 9999
5 9999 3 9999 6
2 3 9999 4 5
7 9999 4 9999 7
9999 6 5 7 9999

3 ----------> 1 = 2
2 ----------> 3 = 3
3 ----------> 4 = 4
3 ----------> 5 = 5

The Minimum Cost is: 14

Press 1. to Retry or press any key to exit: 0
*/
