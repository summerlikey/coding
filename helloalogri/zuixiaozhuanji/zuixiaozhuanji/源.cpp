//问题描述，飞机转机，最小次数
//小哼和小哈一同飞机区旅游，现在在1号城市，目标时5号城市找一种最小次数转机的方式
//
/*
5 7 1 5
1 2
1 3
2 3
2 4
3 4
3 5
4 5


//第一行表示5个城市，7条航线，1表示起点，5表示目标城市，接下来都是航线
*/

//采用广度优先搜索方式

#include<stdio.h>
struct note
{
	int x;//城市编号
	int s;//转机次数
};
int main()
{
	struct note que[2501];
	int e[51][51] = { 0 };
	int book[51] = { 0 };
	int head, tail;
	int i, j,n,m,a,b,start,end,cur,flag=0;

	scanf_s("%d %d %d %d", &n, &m, &start, &end);//分别输入n个城市，m条航线，起点a，终点b
	//初始化二维矩阵
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (i == j)
				e[i][j] = 0;
			else
				e[i][j] = 99999;
	//读入航班信息
	for (i = 1; i <= m; i++)
	{
		scanf_s("%d %d", &a, &b);
		e[a][b] = 1;
		e[b][a] = 1;//无向图
	}
	//初始化队列
	head = 1;
	tail = 1;

	//start 开始end结束
	que[tail].x = start;
	que[tail].s = 0;
	tail++;
	book[start] = 1;//标记start已经在队列中
	//当队列不为空时循环
	while (head < tail)
	{
		cur = que[head].x;//队列首个城市编号
		for (j = 1; j <= n; j++)
		{
			//判断cur到j城市是否有航线，有将j城市加入队尾巴
			if (e[cur][j] != 99999 && book[j] == 0)
			{
				book[j] = 1;
				que[tail].x = j;
				que[tail].s = que[head].s + 1;//转机次数加一，是从队首扩展的
				tail++;

			}
			//如果到达目标城市，停止扩展，任务结束
			if (que[tail].x == end)
			{
				flag = 1;
				break;

			}
		}
		if (flag == 1)
			break;
		head++;
	}
	printf_s("%d", que[tail - 1].s);

	getchar(); getchar();
	return 0;
}