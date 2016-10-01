#include<stdio.h>

void bfs(int,int,int [][10]);

int main(int argc,char **argv[])
{
	int i,j,k,src,n,a[10][10];
	
	do
	{
		printf("\nEnter the number of nodes: ");
		scanf("%d",&n);
		
		printf("\nEnter the adjacency matrix:\n\n");
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		
		printf("\n\nEnter the source node: ");
		scanf("%d",&src);

		bfs(src,n,a);

		printf("\n\nPress 1. to Retry or press any key to exit: ");
		scanf("%d",&k);
	}while(k==1);
	
	return 0;
}

void bfs(int src,int n,int a[10][10])
{
	int q[10],f=0,r=-1,vis[10];
	int i,j;

	for(j=0;j<=n;j++)
	{
		vis[j]=0;
	}

	vis[src]=1;

	r=r+1;
	q[r]=src;

	while(f<=r)
	{
		i=q[f];
		f=f+1;

		printf("%d\t",i);	
		
		for(j=1;j<=n;j++)
		{
			if(a[i][j]==1 && vis[j]!=1)
			{
				vis[j]=1;
				r=r+1;
				q[r]=j;
			}
		}
	}
}

/* Output

Enter the number of nodes: 6

Enter the adjacency matrix:

0 1 0 1 1 0            
0 0 1 0 0 0
0 0 0 0 0 1
0 0 0 0 0 1
0 0 1 0 0 1
0 0 0 0 0 0


Enter the source node: 1
1	2	4	5	3	6	
*/

