//广度优先求最多
#include<stdio.h>
struct note
{
	int x;//横坐标
	int y;//纵坐标
};
char a[20][21];//存储地图

//函数获取该点消灭了多少个敌人
//分为四个方向，同时遇到强停止，遇到怪+1
int getnum(int i, int j)
{
	int sum, x, y;
	sum = 0;
	x = i; y = j;
	//向下统计
	while (a[x][y] != '#')
	{
		if (a[x][y] == 'G')
			sum++;
		x++;
	}
	//向右统计
	x = i;
	y = j;
	while (a[x][y] != '#')
	{
		if (a[x][y] == 'G')
			sum++;
		y++;
	}
	//向上统计
	x = i;
	y = j;
	while (a[x][y] != '#')
	{
		if (a[x][y] == 'G')
			sum++;
		x--;
	}
	//向左统计
	x = i;
	y = j;
	while (a[x][y] != '#')
	{
		if (a[x][y] == 'G')
			sum++;
		y--;
	}
	return sum;
}

int main()
{
	struct note que[401];//队列扩展
	int book[20][20];//标记是否走过
	int head, tail;
	//dingyi炸弹人所走的方向
	int next[4][2]={{0,1},//向右走
	                {1,0},//向下走
	                {0,-1},//向左走
	                {-1,0}//向上走
	};

	int i, j, k, sum, max = 0, mx, my, n, m, startx, starty, tx, ty;
	scanf_s("%d %d %d %d", &n, &m, &startx, &starty);

//	for (i = 0; i <= n-1; i++)
//		for (j = 0; j <= m; j++)
//			scanf_s("%s", a[i]);

	for (int i = 0; i <=n-1; i++)
	{
		for (int j = 0; j <=m-1; j++)
		{
			a[i][j] = getchar();
		}
		getchar();  //这句是为了把输入中每行末尾的换行吸收掉
	}

	//初始化
	head = 1;
	tail = 1;
	book[20][20] = { 0 };
	que[tail].x = startx;
	que[tail].y = starty;
	tail++;
	book[startx][starty] = 1;
	max = getnum(startx,starty);
	max = getnum(7, 11);//测试消灭个数
	printf_s("%d", max);
	mx = startx;
	my = starty;
	while (head < tail)
	{
		//枚举四个方向
		for (k = 0; k <= 3; k++)
		{
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];
			//判断是否越界
			if (tx<0 || tx>n - 1 || ty<0 || ty>m - 1)
				continue;
			//判断是否平地或者已经走过
			if (a[tx][ty] == '.'&&book[tx][ty] == 0)
			{
				book[tx][ty] = 1;
				que[tail].x = tx;
				que[tail].y = ty;
				sum = getnum(tx, ty);
				if (max < sum)
				{
					max = sum;
					mx = tx;
					my = ty;
				}
				tail++;
			}
		}
		head++;


	}
	printf_s("将炸弹放在这个点（%d,%d)消灭的敌人总数最多,可以消灭%d个敌人", mx, my, max);



	getchar(); getchar();
	return 0;
}

/*
//地图
13 13 3 3
#############
#GG.GGG#GGG.#
###.#G#G#G#G#
#.......#..G#
#G#.###.#G#G#
#GG.GGG.#.GG#
#G#.#G#.#.#.#
##G...G.....#
#G#.#G###.#G#
#...G#GGG.GG#
#G#.#G#G#.#G#
#GG.GGG#G.GG#
#############



*/