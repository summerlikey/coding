//����ͼ
//�������е�
//�ڽӾ���

/*
5 5
1 2
1 3
1 5
2 4
3 5


*/
//


//�������������
/*

#include<stdio.h>
int e[51][51] = {99999};
int book[51];
int sum, n;


void dfs(int cur)
{
	int i;
	printf_s("%d", cur);//��ӡ��ǰ���
	sum++;
	if (sum == n)
		return;
	for (i = 1; i <= n; i++)//Ѱ�Һ�cur�����Ľ��
	{
		if (e[cur][i] == 1 && book[i] == 0)
		{
			book[i]=1;
			dfs(i);
		}
	}
	return;
}
int main()
{

	int i, j, m, a, b;
	scanf_s("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (i == j)
				e[i][j] = 0;
			else
				e[i][j] = 99999999;//����δ������
	for (i = 1; i <= m; i++)
	{		scanf_s("%d %d", &a, &b);
	e[a][b] = 1;
	e[b][a] = 1;//����ͼ�����ǶԳƵ�
    }
	book[1] = 1;
	dfs(1);
	getchar();
	getchar();
	return 0;
}
*/

//�������
#include<stdio.h>
int e[101][101];
int book[101];

int main() {
	int i, j, cur, book[101] = { 0 };
	int n, m, a, b;
	int e[101][101];
	int que[10000];
	int head;
	int tail;
	scanf_s("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			if (i == j)
				e[i][j] = 0;
			else
				e[i][j] = 9999;
	for (i = 1; i <= m; i++)
	{
		scanf_s("%d %d", &a, &b);
		e[a][b] = 1;
		e[b][a] = 1;
	}
	//���г�ʼ��
	head = 1;
	tail = 1;
	que[tail] = 1;
	tail++;
	book[1] = 1;

	while (head < tail)
	{

		cur = que[head];
		for (i = 1; i <= n; i++)
		{
			if (e[cur][i] == 1 && book[i] == 0)
			{
				que[tail] = i;
				tail++;
				book[i] = 1;//���i�ѷ���
			}
			if (tail > n)
				break;

		}
		head++;

	}
	for (i = 1; i < tail; i++)
	{
		printf_s("%d ", que[i]);
	}
	getchar(); getchar();

	return 0;
}
