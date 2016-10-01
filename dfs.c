#include<stdio.h>

void dfs(int);

int a[10][10],n,count,vis[10],flag = 0;

int main(int argc, char **argv[])
{
	int i,j;

		printf("\nEnter the number of nodes: ");
		scanf("%d",&n);

		printf("\nEnter the adjacency matrix:\n\n");
		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= n; j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		printf("\n");

		for(i = 1;i <= n; i++)
		{
			if(flag == 1)
			{
				break;
			}
			count = n;

			for(j = 1; j <= n; j++)
				vis[j] = 0;

			dfs(i);

			if(count == 0)
				printf("\nThe graph is connected wrt to source vertex %d\n\n",i);
			else
			{
				printf("\nThe graph is not connected wrt to source vertex %d\n\n",i);
				flag = 1;
			}

		}

		if(flag == 1)
		{
			printf("\nHence the graph is not a connected graph\n\n");
		}
		else
		{
			printf("\nHence the graph is a connected graph\n\n");
		}
	
	return 0;
}

void dfs(int src)
{
	int i,j;

	printf("%d\t",src);

	count--;
	vis[src] = 1;

	for(j = 1; j <= n; j++){
		if(a[src][j] == 1 && vis[j] != 1)
			dfs(j);
	}

}

/* Output

Enter the number of nodes: 4

Enter the adjacency matrix:

0 1 0 0
0 0 1 0
0 0 0 1
0 0 0 0

1	2	3	4
The graph is connected wrt to source vertex 1

2	3	4
The graph is not connected wrt to source vertex 2


Hence the graph is not a connected graph


Enter the number of nodes: 4

Enter the adjacency matrix:

0 1 0 0
0 0 1 0
0 0 0 1
1 0 0 0
1	2	3	4
The graph is connected wrt to source vertex 1

2	3	4	1
The graph is connected wrt to source vertex 2

3	4	1	2
The graph is connected wrt to source vertex 3

4	1	2	3
The graph is connected wrt to source vertex 4


Hence the graph is a connected graph
*/




