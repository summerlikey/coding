//�����������ɻ�ת������С����
//С�ߺ�С��һͬ�ɻ������Σ�������1�ų��У�Ŀ��ʱ5�ų�����һ����С����ת���ķ�ʽ
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


//��һ�б�ʾ5�����У�7�����ߣ�1��ʾ��㣬5��ʾĿ����У����������Ǻ���
*/

//���ù������������ʽ

#include<stdio.h>
struct note
{
	int x;//���б��
	int s;//ת������
};
int main()
{
	struct note que[2501];
	int e[51][51] = { 0 };
	int book[51] = { 0 };
	int head, tail;
	int i, j,n,m,a,b,start,end,cur,flag=0;

	scanf_s("%d %d %d %d", &n, &m, &start, &end);//�ֱ�����n�����У�m�����ߣ����a���յ�b
	//��ʼ����ά����
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (i == j)
				e[i][j] = 0;
			else
				e[i][j] = 99999;
	//���뺽����Ϣ
	for (i = 1; i <= m; i++)
	{
		scanf_s("%d %d", &a, &b);
		e[a][b] = 1;
		e[b][a] = 1;//����ͼ
	}
	//��ʼ������
	head = 1;
	tail = 1;

	//start ��ʼend����
	que[tail].x = start;
	que[tail].s = 0;
	tail++;
	book[start] = 1;//���start�Ѿ��ڶ�����
	//�����в�Ϊ��ʱѭ��
	while (head < tail)
	{
		cur = que[head].x;//�����׸����б��
		for (j = 1; j <= n; j++)
		{
			//�ж�cur��j�����Ƿ��к��ߣ��н�j���м����β��
			if (e[cur][j] != 99999 && book[j] == 0)
			{
				book[j] = 1;
				que[tail].x = j;
				que[tail].s = que[head].s + 1;//ת��������һ���ǴӶ�����չ��
				tail++;

			}
			//�������Ŀ����У�ֹͣ��չ���������
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