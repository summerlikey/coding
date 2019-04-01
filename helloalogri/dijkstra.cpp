#include <stdio.h>
int main()
{
	int e[10][10];
	int dis[10];
	int book[10];
	int i,j;
	int n,m;
	int t1,t2,t3;
	int u,v,min;
	int inf=99999999;//inf表示无限远
	scanf("%d %d",&n,&m);
	//初始化
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i==j)
				e[i][j]=0;
			else
				e[i][j]=inf;
	//读入边
	for(i=1;i<=m;i++)
	{
		scanf("%d %d %d",&t1,&t2,&t3);
		e[t1][t2]=t3;
	}
	//初始化dis数组，这里1号到各点的初始路程
	for(i=1;i<=n;i++)
		dis[i]=e[1][i];
	//book 初始化
	for(i=1;i<=n;i++)
		book[i]=0;
	book[1]=1;
	//dijkstra算法核心
	for(i=1;i<=n-1;i++)
	{
		//找到离一号最近的点
		min=inf;
		for(j=1;j<=n;j++)
		{
			if(book[j]==0&&dis[j]<min)
			{
				min=dis[j];
				u=j;
			}
		}
		book[u]=0;
		for(v=1;v<=n;v++)
		{
			if(e[u][v]<inf)
			{
				if(dis[v]>dis[u]+e[u][v])
					dis[v]=dis[u]+e[u][v];
			}
		}
	}
	//
	for(i=1;i<=n;i++)
		printf("%d ",dis[i]);
}
/*
6 9
1 2 1
1 3 12
2 3 9
2 4 3
3 5 5
4 3 4
4 5 13
4 6 15
5 6 4
*/
