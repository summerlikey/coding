
//采用广度优先搜索，直接扩展岛的面积
//岛的数据
/*

10 10 6 8
1 2 1 0 0 0 0 0 2 3
3 0 2 0 1 2 1 0 1 2
4 0 1 0 1 2 3 2 0 1
3 2 0 0 0 1 2 4 0 0
0 0 0 0 0 0 1 5 3 0
0 1 2 1 0 1 5 4 3 0
0 1 2 3 1 3 6 2 1 0
0 0 3 4 8 9 7 5 0 0
0 0 0 3 7 8 6 0 1 2
0 0 0 0 0 0 0 0 1 0

*/
//广度优先原则
/*

#include<stdio.h>

struct note
{
	int x;
	int y;
};

int a[10][10];
int book[10][10];

int main()
{
	int i,j,n,m,k,tx,ty,startx,starty,sum;
	int head, tail;
	struct note que[101];
	scanf_s("%d %d %d %d", &n, &m, &startx, &starty);
	//输入地图
	for (i = 0; i <= n - 1; i++)
		for (j = 0; j <= m - 1; j++)
			scanf_s("%d", &a[i][j]);
	//每一个点有4个方向可以移动
	int next[4][2] = {
		{0,1},{1,0},{0,-1},{-1,0}
	};
	//初始化
	head = 1;
	tail = 1;
	que[tail].x = startx;
	que[tail].y = starty;
	tail++;
	book[startx][starty] = 1;
	sum = 1;
	while (head < tail)
	{
		for (k = 0; k <= 3; k++)
		{
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];
			if (tx<0 || tx>n - 1 || ty<0 || ty>m - 1)
				continue;
			if (a[tx][ty] > 0 && book[tx][ty] == 0)
			{
				que[tail].x = tx;
				que[tail].y = ty;
				book[tx][ty] = 1;
				sum++;
				tail++;
			}
		}
		head++;
	}
	printf_s("%d", sum);
	getchar(); getchar();
	return 0;
}
*/


//采用深度优先原则，重要的是每一步的递归

#include <stdio.h>
int a[51][51];
int book[51][51] = { 0 };//标记作用
int n, m, sum;
int color;//给岛着色
//深度搜索核心代码
void dfs(int x, int y,int color)
{
	//定义走的四个方向
	int next[4][2] = {
		{0,1},{1,0},{0,-1},{-1,0}
	};
	int k,tx,ty;
	//同理不需要终点，直接遍历所有未标记的点
	//每一步可以有四个选择，所以枚举四个方向
	for (k = 0; k <= 3; k++)
	{
		tx = x + next[k][0];
		ty = y + next[k][1];

		if (tx<0 || tx>n - 1 || ty<0 || ty>m - 1)
			continue;
		if (a[tx][ty] > 0 && book[tx][ty] == 0)
		{
			book[tx][ty] = 1;
			a[tx][ty] = color;
			dfs(tx, ty,color);
			sum++;
		}

	}

	return;
}
int main()
{
	int startx, starty, i, j;
	color = -1;
	scanf_s("%d %d %d %d", &n, &m, &startx, &starty);
	for (i = 0; i <= n - 1; i++)
		for (j = 0; j <= m - 1; j++)
			scanf_s("%d", &a[i][j]);
	sum = 1;
	book[startx][starty] = 1;
	dfs(startx, starty, color);
	printf_s("%d\n", sum);
	for (i = 0; i <= n - 1; i++)
	{
		for (j = 0; j <= m - 1; j++)
			printf_s("%d ", a[i][j]);
		
		printf_s("\n");
		
	}
	getchar();getchar();
	return 0;
}