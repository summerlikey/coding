//��ͼ��һ���㵽�����ľ���
//����ͼʱ
//��������
/*
5 8
1 2 2
1 5 10
2 3 3
2 5 7
3 1 4
3 4 4
4 5 5
5 3 3



*/

//�����������̾���
/*
#include<stdio.h>
int min = 99999999, book[101], n, e[101][101];

//cur��ʾ��ǰ���б��

void dfs(int cur, int dis)//dis��ʾ�Ѿ��߹��ľ���
{
	int j;
	if (dis > min)
		return;
	if (cur == n)//�ж��Ƿ񵽴����
	{
		if (dis < min)
			min = dis;//������Сֵ
		return;
	}
	for (j = 1; j <= n; j++)
	{
		if (e[cur][j] != 9999999 && book[j] == 0)
		{
			book[j] = 1;
			dfs(j, dis + e[cur][j]);
			book[j] = 0;
		}
	}
	return;

}
int main()
{
	int i, j, m, a, b, c;
	scanf_s("%d %d", &n, &m);
	//��ʼ����ά����
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (i == j)
				e[i][j] = 0;
			else
				e[i][j] = 99999999;
	for (i = 1; i <= m; i++)
	{
		scanf_s("%d %d %d", &a, &b, &c);
		e[a][b] = c;
	}
	book[1] = 1;
	dfs(1, 0);
	printf_s("%d ",min);


	getchar(); getchar();
	return 0;

}
*/

//�������̾���
#include<stdio.h>
int main()
{
	int e[101][101];
	int que[10001], i, j, n, m, cur, a, b, c, book[10000] = { 0 },flag;
	int min = 999999,dis=0;
	int mmin = 9999;
	int head;
	int tail;
	scanf_s("%d %d", &n, &m);//n�����У�m��·
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (i == j)
				e[i][j] = 0;
			else
				e[i][j] = 99999;
	for (i = 1; i <= m; i++)
	{
		scanf_s("%d %d %d", &a, &b, &c);
		e[a][b] = c;
	}
	//��ʼ������
	head = 1;
	tail = 1;
	que[tail] = 1;
	tail++;
	book[1] = 1;
	while (head < tail)
	{
		cur = que[head];//��ǰ�Ľ��
		for (i = 1; i <= n; i++)
		{
			if (e[cur][i] != 99999 && book[i] == 0)
			{
				book[i] = 1;
				que[tail] = i;
				dis = dis + e[cur][i];
		
				
			}
			if (i == c)
			{
				flag = 1;
				if (min > dis)
					min = dis;
				break;
			}
		}
		if (flag == 1)
		{
			if (mmin > min)
				mmin = min;
			break;
		}

		head++;

	}
	printf_s("%d ", min); 
	getchar(); getchar();
	return 0;

}