//������������
#include<stdio.h>
struct note
{
	int x;//������
	int y;//������
};
char a[20][21];//�洢��ͼ

//������ȡ�õ������˶��ٸ�����
//��Ϊ�ĸ�����ͬʱ����ǿֹͣ��������+1
int getnum(int i, int j)
{
	int sum, x, y;
	sum = 0;
	x = i; y = j;
	//����ͳ��
	while (a[x][y] != '#')
	{
		if (a[x][y] == 'G')
			sum++;
		x++;
	}
	//����ͳ��
	x = i;
	y = j;
	while (a[x][y] != '#')
	{
		if (a[x][y] == 'G')
			sum++;
		y++;
	}
	//����ͳ��
	x = i;
	y = j;
	while (a[x][y] != '#')
	{
		if (a[x][y] == 'G')
			sum++;
		x--;
	}
	//����ͳ��
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
	struct note que[401];//������չ
	int book[20][20];//����Ƿ��߹�
	int head, tail;
	//dingyiը�������ߵķ���
	int next[4][2]={{0,1},//������
	                {1,0},//������
	                {0,-1},//������
	                {-1,0}//������
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
		getchar();  //�����Ϊ�˰�������ÿ��ĩβ�Ļ������յ�
	}

	//��ʼ��
	head = 1;
	tail = 1;
	book[20][20] = { 0 };
	que[tail].x = startx;
	que[tail].y = starty;
	tail++;
	book[startx][starty] = 1;
	max = getnum(startx,starty);
	max = getnum(7, 11);//�����������
	printf_s("%d", max);
	mx = startx;
	my = starty;
	while (head < tail)
	{
		//ö���ĸ�����
		for (k = 0; k <= 3; k++)
		{
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];
			//�ж��Ƿ�Խ��
			if (tx<0 || tx>n - 1 || ty<0 || ty>m - 1)
				continue;
			//�ж��Ƿ�ƽ�ػ����Ѿ��߹�
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
	printf_s("��ը����������㣨%d,%d)����ĵ����������,��������%d������", mx, my, max);



	getchar(); getchar();
	return 0;
}

/*
//��ͼ
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