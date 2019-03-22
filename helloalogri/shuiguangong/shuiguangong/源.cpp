//分析可以用深度和宽度搜索两种方式解题
//使用深度搜索时
//有两种管子，一种是直观，一种是弯管，直管有两种状态，弯管有4中状态，弯管和直管同一类中都可以相互转换
//
/*
5 4
5 3 5 3
1 5 3 0
2 3 5 1
6 1 1 5
1 5 5 4

*/


//深度搜索
#include<stdio.h>
int a[51][51];
int book[51][51];
int n, m;
int flag=0;
void dfs(int x, int y, int front)
{
	int i;
	if (x==n&& y==m + 1)
	{
		flag = 1;
		return;
	}
	if (x<1 || x>n || y<1 || y>m)//越界，此路不通
		return;
	if (book[x][y] == 1)
		return;
	if (a[x][y] >= 5 && a[x][y] <= 6)
	{
		if (front == 1)//进水口在左边
		{
			dfs(x, y + 1, 1);//用5这种方式，进水口在左边
		}
		if (front == 2)
		{
			dfs(x + 1, y, 2);//只能用6号方式
		}
		if (front == 3)
			dfs(x, y - 1, 3);//如果进水口在右边，只能用5号方式
		if (front == 4)
			dfs(x - 1, y, 4);//如果进水口在下面
	}
	if (a[x][y] >= 1 && a[x][y] <= 4)
	{
		if (front == 1)//进水口在左边
		{
			dfs(x -1, y, 4);
			dfs(x = 1, y, 2);
		}
		if (front == 2)//进水口在上边
		{
			dfs(x, y + 1, 1);
			dfs(x, y - 1, 3);
		}
		if (front == 3)//进水口在右边
		{
			dfs(x - 1, y, 4);
			dfs(x + 1, y, 2);
		}
		if (front == 4)
		{
			dfs(x, y + 1, 1);
			dfs(x, y - 1, 3);
		}
	}
	book[x][y]=0;//取消标记
	return;

}


int main()
{
	int i, j, num;
	scanf_s("%d %d", &n, &m);
	//读入游戏地图
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			scanf_s("%d", &a[i][j]);
	dfs(1, 1, 1);
	if (flag == 0)
	    printf_s("impossible\n");
	else
		printf_s("找到铺设方案\n");
	getchar(); getchar();
	return 0;
}