//������������ȺͿ���������ַ�ʽ����
//ʹ���������ʱ
//�����ֹ��ӣ�һ����ֱ�ۣ�һ������ܣ�ֱ��������״̬�������4��״̬����ܺ�ֱ��ͬһ���ж������໥ת��
//
/*
5 4
5 3 5 3
1 5 3 0
2 3 5 1
6 1 1 5
1 5 5 4

*/


//�������
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
	if (x<1 || x>n || y<1 || y>m)//Խ�磬��·��ͨ
		return;
	if (book[x][y] == 1)
		return;
	if (a[x][y] >= 5 && a[x][y] <= 6)
	{
		if (front == 1)//��ˮ�������
		{
			dfs(x, y + 1, 1);//��5���ַ�ʽ����ˮ�������
		}
		if (front == 2)
		{
			dfs(x + 1, y, 2);//ֻ����6�ŷ�ʽ
		}
		if (front == 3)
			dfs(x, y - 1, 3);//�����ˮ�����ұߣ�ֻ����5�ŷ�ʽ
		if (front == 4)
			dfs(x - 1, y, 4);//�����ˮ��������
	}
	if (a[x][y] >= 1 && a[x][y] <= 4)
	{
		if (front == 1)//��ˮ�������
		{
			dfs(x -1, y, 4);
			dfs(x = 1, y, 2);
		}
		if (front == 2)//��ˮ�����ϱ�
		{
			dfs(x, y + 1, 1);
			dfs(x, y - 1, 3);
		}
		if (front == 3)//��ˮ�����ұ�
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
	book[x][y]=0;//ȡ�����
	return;

}


int main()
{
	int i, j, num;
	scanf_s("%d %d", &n, &m);
	//������Ϸ��ͼ
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			scanf_s("%d", &a[i][j]);
	dfs(1, 1, 1);
	if (flag == 0)
	    printf_s("impossible\n");
	else
		printf_s("�ҵ����跽��\n");
	getchar(); getchar();
	return 0;
}