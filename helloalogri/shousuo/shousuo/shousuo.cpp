//全排列

#include "pch.h"
#include <iostream>
/*
int a[10], book[10], n;
void dfs(int step)//step表示站在第几个盒子面前
{
	int i;
	if (step == n + 1)//如果站在第n+1个盒子面前，则表示前n个盒子已经放好扑克牌
	{
		//输出一种排列（1-n号盒子中的扑克牌编号)
		for (i = 1; i <= n; i++)
			printf_s("%d", a[i]);
		printf_s("\n");
		return;
	}
	for (i = 1; i <= n; i++)
	{
		if (book[i] == 0)//book[i]表示牌还在手上
		{
			//开始尝试使用扑克牌
			a[step] = i; //将i号扑克牌放入step个盒子中
				book[i] = 1;//将i号扑克牌放入第step个盒子中
			//第step个盒子已经放好扑克牌，接下来走到另一个盒子面前
				dfs(step + 1);//使用函数的递归调用来实现（自己调用自己）
				book[i] = 0;//将刚才尝试的扑克牌收回，然后进行下一个尝试
		}
	}
	return;
}

int main()
{
	scanf_s("%d", &n);//输入的时候要注意n为1-9之间的整数
	dfs(1);//首先站在1号小盒子前面
	return 0;
	
}
*/
//下面为自己默写

/*
int a[10], book[10], n;
void dfs(int step)
{
	int i = 0;
	if (step == n + 1)
	{
		for (i = 1; i <= n; i++)
		{
			printf_s("%d ", a[i]);
		}
		printf_s("\n");
		return;
	}

	for (i = 1; i <= n; i++)
	{
		if (book[i] == 0)//使用book标记0为没使用，1为已使用
		{
			a[step] = i;
			book[i] = 1;//已使用就标记为1
			dfs(step + 1);//进入下一个位置
			book[i] = 0;//返回时清除
		}
	}
	return;
}
int main()
{
	scanf_s("%d", &n);
	dfs(1);
	return 0;
}

*/


//下面使用a,b,c进行全排列
int book[10], n;
char a[10];
char b[10];
void dfs(int step)
{
	int i = 0;
	if (step == n + 1)
	{
		for (i = 1; i <= n; i++)
		{
			printf_s("%c ", b[i]);
		}
		printf_s("\n");
		return;
	}

	for (i = 1; i <= n; i++)
	{
		if (book[i] == 0)//book为标记位当为0时没有使用
		{
			b[step] = a[i];
			book[i] = 1;
			dfs(step + 1);
			book[i] = 0;
		}
	}

	return;
}


int main()
{
	int i;
	scanf_s("%d", &n);
	//输入需要全排列的元素个数
	gets_s(a);//输入元素中间留一个空格占用a[0]位
	


	for (i = 1; i <= n; i++)
	{
		printf_s("%c ", a[i]);
	}

	dfs(1);

	return 0;
}