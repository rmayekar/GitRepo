/***********************************************************************
Program Name	: Dijikstra.cpp
Compiler		: Gcc,Redhat
Author		: Hari Shankar.
USN			: 1PE08IS035
Date                            : 26.1.2010
***********************************************************************/
#include<iostream>
#include<stdlib.h>
using namespace std;

class graph
{
	private:
		int cost[10][10],d[10],p[10],visited[10];
		int n,src;
	public:
		void getdata();
		void dijkstras();
		void putdata();
};
/***********************************************************************
Function Name	:void getdata()
Description		:Takes the cost matrix as input
Input Parameters	:The no. of vertices
Returns		:void(takes cost[][] as input)
***********************************************************************/
void graph::getdata()
{
	int i,j;
	cout<<"Enter the number of vertices in the Graph"<<endl;
	cin>>n;
	cout<<"Enter the Cost matrix of the Graph"<<endl;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			cin>>cost[i][j];
		}
	}
	cout<<"The Cost Matrix is"<<endl;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			cout<<cost[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<"Enter the source vertex"<<endl;
	cin>>src;
}
/***********************************************************************
Function Name	:void dijikstras()
Description		:Implements dijikstra’s algorithm to find shortest path from source
Input Parameters	:Cost matrix
Returns		:void(finds shortest path from source)
***********************************************************************/
void graph::dijkstras()
{
	int i,j,min,u,v;
	for (i=1;i<=n;i++)
	{
		d[i]=cost[src][i];
		visited[i]=0;
		p[i]=src;
	}
	visited[src]=1;
	for (i=1;i<=n;i++)
	{
		min=9999;
		u=0;
		for (j=1;j<=n;j++)
		{
			if (!visited[j])
			{
				if (d[j]<min)
				{
					min=d[j];
					u=j;
				}
			}
		}
		visited[u]=1;
		for (v=1;v<=n;v++)
		{
			if ((!visited[v])&& (d[u]+cost[u][v]<d[v]))
			{
				d[v]=d[u]+cost[u][v];
				p[v]=u;
			}
		}
	}
}
/***********************************************************************
Function Name	:void putdata()
Description		:Gives shortest path from source vertex
Input Parameters	:Cost matrix
Returns		:void(gives shortest path from source vertex)
***********************************************************************/
void graph::putdata()
{
	int i,k,parent;
	for (i=1;i<=n;i++)
	{
		if(i == src){
			continue;
		}
		cout<<"The Shortest Path from " <<src<<" to " <<i<< " is : ";
		k = i;
		cout << src << " -> ";
		while (p[k]!=src)
		{
			cout<<p[k]<<" -> ";
			k = p[k];
		}
		cout<<i;
		cout<<" and the cost is : " <<d[i]<<endl;
	}
}
/***********************************************************************
Function Name	: int main(int argc,char **argv)
Description		:Implements Dijikstras algorithm
Input Parameters	:argc – No. of input parameters in command line
			 Argv – List of input parameters in command line
Returns		:0 – If executed successfully Otherwise returns -1.
***********************************************************************/
int main(int argc,char **argv)
{
	graph g;
	g.getdata();
	g.dijkstras();
	g.putdata();
	return(0);
}

/* OUTPUT
Enter the number of vertices in the Graph
5
Enter the Cost matrix of the Graph

0	3	9999	7	9999	
3	0	4	2	9999	
9999	4	0	5	6	
7	2	5	0	4	
9999	9999	6	4	9999	

Enter the source vertex
1

The Shortest Path from 1 to 2 is : 2 <- 1 and the cost is : 3
The Shortest Path from 1 to 3 is : 3 <- 2 <- 1 and the cost is : 7
The Shortest Path from 1 to 4 is : 4 <- 2 <- 1 and the cost is : 5
The Shortest Path from 1 to 5 is : 5 <- 4 <- 2 <- 1 and the cost is : 9
*/
