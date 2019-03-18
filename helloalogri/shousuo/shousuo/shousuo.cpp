//全排列

#include "pch.h"
#include <iostream>
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

