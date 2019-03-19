//广度优先搜索又称宽度优先原则

#include "pch.h"
#include <iostream>
struct node
{
	int x;//横坐标
	int y;//纵坐标
	int f;//父亲在队列中的编号，本题不需要输出路径，可以不需要f
	int s;//步数
};


int main()
{

	struct node que[2501];//地图大小不超过50*50，因此队列扩展不会超过2500个
	int a[51][51] = { 0 };//初始化地图
	int book[51][51] = { 0 };//初始化还没有走过的地图，0为未走过，防止一个点被重复扩展
	//定义一个表示方向的数组
	int next[4][2] = { {0,1},//向右走
	                   {1,0},//向下走
					   {0,-1},//向左走
	                   {-1,0} };//向上走

	int head = 1;//队列初始化，设置为开始
	int tail = 1;//队列初始化
	//将（1，1）加入队列，并标记（1,1)已经走过
	int i, j, k, n, m, startx, starty, p, q, tx, ty, flag;
	scanf_s("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			scanf_s("%d", &a[i][j]);
	scanf_s("%d %d %d %d", &startx, &starty, &p, &q);
	que[tail].x = startx;
	que[tail].y = starty;
	que[tail].s = 0;
	que[tail].f = 0;
	tail++;
	book[startx][starty] = 1;
	flag = 0;//标记是否到达目标点，0表示暂时还没有达到，1表示到达
	//当队列不为空时循环
	while (head < tail)
	{
		//枚举四个扩展方向
		for (k = 0; k <= 3; k++)
		{
			//计算下一个点的坐标
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];
			//判断是否越界
			if (tx<1 || tx>n || ty<1 || ty>m)
				continue;
			//判断是否在路径中
			if (a[tx][ty] == 0 && book[tx][ty] == 0)
			{
				//标记点为走过
				//同时将点入队列，将父点出列
				book[tx][ty] = 1;
				que[tail].x = tx;
				que[tail].y = ty;
				que[tail].f = head;//这点是从head点扩展出来
				que[tail].s = que[head].s + 1;//步数是父亲的步数+1
				tail++;
			}
			//如果到目标点了，则停止扩展，退出循环
			if (tx == p && ty == q)
			{
				//
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
		head++;//当一个点扩展完后，才能对head++扩展
	}
	printf_s("%d\n", que[tail - 1].s);
	while (tail > 1)
	{
		printf_s("%d %d \n", que[tail - 1].x, que[tail - 1].y);
		tail--;
	}

	return 0;
}

