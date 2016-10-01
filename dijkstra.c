#include<stdio.h>

void dijkstra(int,int,int [],int [],int [][10]);

int main(int argc, char **argv[])
{
	int i,j,n,src,vis[10],dist[10],c[10][10];
	int key;
	
	do{
		printf("\nEnter the number of vertices: ");
		scanf("%d",&n);

		printf("\nEnter the Adjacency matrix:\n\n");
		for(i = 1; i <= n; i++)
			for(j = 1; j <= n;j++)
				scanf("%d",&c[i][j]);

		printf("\n\nEnter the source node: ");
		scanf("%d",&src);

		dijkstra(n,src,vis,dist,c);

		printf("\n\nPress 1. to Retry or press any key to exit: ");
		scanf("%d",&key);
	}while(key == 1);
	
	return 0;
}

void dijkstra(int n, int src, int vis[10], int dist[10], int c[][10])
{
	int count = 1,j,min,u;

	for(j = 1; j<= n; j++)
		dist[j] = c[src][j];

	for(j = 1; j <= n; j++)
		vis[j] = 0;

	dist[src] = 0;
	vis[src] = 1;

	while(count != n){
		min = 9999;
		
		for(j = 1; j <= n; j++){
			if(dist[j] < min && vis[j] != 1){
				min = dist[j];
				u = j;
			}
		}

		for(j = 1; j <= n; j++){
			if(min + c[u][j] < dist[j] && vis[j] != 1)
				dist[j] = min + c[u][j];
		}

		vis[u] = 1;
		count++;
	}

	printf("\n\nThe shortest distance form %d is:\n\n",src);
	for(j = 1; j <= n; j++)
		printf("%d ----------> %d = %d\n",src,j,dist[j]);
}

/* Output

Enter the number of vertices: 5

Enter the Adjacency matrix:

9999 3 9999 7 9999
3 9999 4 2 9999
9999 4 9999 5 6
7 2 5 9999 4
9999 9999 6 4 9999


Enter the source node: 1


The shortest distance form 1 is:

1 ----------> 1 = 0
1 ----------> 2 = 3
1 ----------> 3 = 7
1 ----------> 4 = 5
1 ----------> 5 = 9


Press 1. to Retry or press any key to exit: 0
*/
	

