#include<stdio.h>
#define inf 999 
void prims();
void kruskal();
int findset(int i);
int unio(int i,int j);
void print(int printst[][50],int pmct,int nv);
int parent[50];
void main()
{
	int ans=1,choice;
    while(ans==1)
	{
    	printf("\n1.Kruskal");
    	printf("\n2.Prim");
    	printf("\nEnter your choice:");
    	scanf("%d",&choice);
    	switch(choice)
    	{
    		case 1: kruskal();
    				break;
    		case 2: prims();
    				break;
    		default:printf("\nwrong choice");
    				break;
    	}
		printf("\nDo you want to try again enter 1 if yes:");
		scanf("%d",&ans);
    }
}
void kruskal()
{
	int i,j,k,ta,tb,tu,tv,n,count=1,min,mct=0,cost[50][50],span[50][50];
	printf("\nEnter the no. of vertices:");
	scanf("%d",&n);
	printf("\nEnter the cost adjacency matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=999;
			else
				span[i][j]=0;
		}
	}
	for(i=1;i<=n;i++)
		parent[i]=-1;
	while(count<n)
	{
		min=999;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(cost[i][j]<min)
				{
					min=cost[i][j];
					ta=tu=i;
					tb=tv=j;
				}
			}
		}
		while(parent[tu]!=-1)
			tu=parent[tu];
		while(parent[tv]!=-1)
			tv=parent[tv];
		if(tu!=tv)
		{
			printf("\nEdge from (%d-%d)=%d",ta,tb,min);
			mct=mct+min;
			count++;
			printf("\nMin cost=%d",mct);
			span[ta][tb]=min;
			span[tb][ta]=min;
			parent[tv]=tu;
		}
		cost[ta][tb]=cost[tb][ta]=999;
	}
	print(span,mct,n);
}
void prims()
{
	int cost[50][50],spant[50][50],i,j,count=0,distance[50],previous[50],visited[50],min,nextnode,prev,mincost=0,graph[50][50],n,s;
	printf("Enter no. of vertices:");
    scanf("%d",&n);
    printf("\nEnter the Edge weight matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            scanf("%d",&graph[i][j]);
    }
    printf("\nEnter the starting node:");
    scanf("%d",&s);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(graph[i][j]==0)
			{
				cost[i][j]=inf;
				spant[i][j]=0;
			}
			else
			{
				cost[i][j]=graph[i][j];
				spant[i][j]=0;
			}
		}
	}
	for(i=1;i<=n;i++)
    {
        distance[i]=cost[s][i];
        previous[i]=s;
        visited[i]=0;
    }
    distance[s]=0;
    visited[s]=1;
    while(count<n-1)
    {
    	min=inf;
    	for(i=1;i<=n;i++)
    	{
    		if(visited[i]!=1&&distance[i]<min)
    		{
    			min=distance[i];
    			nextnode=i;
    		}
    	}
    	prev=previous[nextnode];
    	printf("\nEdge from (%d-%d)=%d",prev,nextnode,distance[nextnode]);
    	visited[nextnode]=1;
    	spant[prev][nextnode]=distance[nextnode];
    	spant[nextnode][prev]=distance[nextnode];
    	for(i=1;i<=n;i++)
    	{
    		if(visited[i]!=1&&cost[i][nextnode]<distance[i])
    		{
    			distance[i]=cost[i][nextnode];
    			previous[i]=nextnode;
    		}
    	}
    	mincost=mincost+cost[prev][nextnode];
    	printf("\nMin Cost=%d",mincost);
    	count++;
    }
	print(spant,mincost,n);
}
void print(int printst[][50],int pmct,int nv)
{
	int i,j;
	printf("\nSpanning tree\n");
    for(i=1;i<=nv;i++)
    {
    	for(j=1;j<=nv;j++)
    	{
    		printf("%d\t",printst[i][j]);
    	}
    	printf("\n");
    }
    printf("\nTotal minimum cost=%d",pmct);
}
/*Output
tejal@ubuntu:~/Desktop$ gcc mst.c
tejal@ubuntu:~/Desktop$ ./a.out

1.Kruskal
2.Prim
Enter your choice:1

Enter the no. of vertices:7

Enter the cost adjacency matrix:
0 7 0 5 0 0 0
7 0 8 9 7 0 0
0 8 0 0 5 0 0
5 9 0 0 15 6 0
0 7 5 15 0 8 9
0 0 0 6 8 0 11
0 0 0 0 9 11 0

Edge from (1-4)=5
Min cost=5
Edge from (3-5)=5
Min cost=10
Edge from (4-6)=6
Min cost=16
Edge from (1-2)=7
Min cost=23
Edge from (2-5)=7
Min cost=30
Edge from (5-7)=9
Min cost=39
Spanning tree
0	7	0	5	0	0	0	
7	0	0	0	7	0	0	
0	0	0	0	5	0	0	
5	0	0	0	0	6	0	
0	7	5	0	0	0	9	
0	0	0	6	0	0	0	
0	0	0	0	9	0	0	

Total minimum cost=39
Do you want to try again enter 1 if yes:1

1.Kruskal
2.Prim
Enter your choice:2
Enter no. of vertices:8

Enter the Edge weight matrix:
0 10 5 15 20 0 0 0 
10 0 10 0 0 30 0 0
5 10 0 5 0 5 30 0
15 0 5 0 50 0 15 25
20 0 0 50 0 0 0 0
0 30 5 0 0 0 40 0
0 0 30 15 0 40 0 30
0 0 0 25 0 0 30 0

Enter the starting node:7

Edge from (7-4)=15
Min Cost=15
Edge from (4-3)=5
Min Cost=20
Edge from (3-1)=5
Min Cost=25
Edge from (3-6)=5
Min Cost=30
Edge from (3-2)=10
Min Cost=40
Edge from (1-5)=20
Min Cost=60
Edge from (4-8)=25
Min Cost=85
Spanning tree
0	0	5	0	20	0	0	0	
0	0	10	0	0	0	0	0	
5	10	0	5	0	5	0	0	
0	0	5	0	0	0	15	25	
20	0	0	0	0	0	0	0	
0	0	5	0	0	0	0	0	
0	0	0	15	0	0	0	0	
0	0	0	25	0	0	0	0	

Total minimum cost=85
Do you want to try again enter 1 if yes:2
tejal@ubuntu:~/Desktop$ 
*/
