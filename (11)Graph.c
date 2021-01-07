#include <stdio.h>
#include <stdlib.h>
#define size 20

void dfs_search(int adj_m[][size], int visited[], int src, int n);
void bfs (int adj_m[][size],int node,int n);
void read_adj_m(int a[][size],int n);
void main()
{
	int n, adj_m[size][size], source,ch, visited[size]={0}, i, j;
	printf("Enter the no. of cities\n");
	scanf("%d", &n);
	while(1)
	{
		printf("\n\nEnter your choice\n1.Create\n2.print\n3.Search if the give city can reach the other cities\n4.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:read_adj_m(adj_m,n);
				break;
			case 2:	for(i=0;i<n;i++)
				{
					bfs(adj_m,i,n);
				}
				break;
			case 3:	printf("Enter Source\n");
				scanf("%d", &source);
				for(i=0;i<n;i++)
				{
					visited[i]=0;
				}
				dfs_search(adj_m, visited, source, n);
				for (i = 0; i < n; i++)
				{
						if (visited[i] == 0)
							printf("%d is not reachable\n", i);
						else
							printf("%d is reachable\n", i);
				}	
				break;
				
			default:exit(0);
		}
	}
}			
					
				
		
		
void read_adj_m(int adj_m[][size],int n)
{
	int i,j;
	printf("\nEnter the Coef. Adjacency Matrix\n");
	for (i = 0; i < n; i++)
	{
		printf("the nodes connected to city %d :",i);
		for (j = 0; j < n; j++)
			scanf("%d", &adj_m[i][j]);
	}
}

void bfs(int adj_m[][size],int node,int n)
{
	int Q[size], rear = -1, front = 0, u, v;
	int visit[size] = {0};
	printf("\nthe nodes connected to city %d :",node);
	Q[++rear]=node ;
	visit[node]=1;
	while (front <= rear)
	{
		
		u = Q[front++];
		printf("%d\t",u);	
		for (v = 0; v < n; v++)
		{
			if ((adj_m[u][v] == 1) && (visit[v] == 0))
			{
				Q[++rear] = v;
				visit[v] = 1;
			}
		}
	}
}

void dfs_search(int adj_m[][size], int visited[], int src, int n)
{
	int s[size], top=-1,u, v;
	visited[src] = 1;
	s[++top] = src;
	while (top>-1)
	{
		u = s[top--];
		for (v = 0; v < n; v++)
		{
			if ((adj_m[u][v] == 1) && (visited[v] == 0))
			{
				s[++top] = v;
				visited[v] = 1;
			}
		}
	}
}
