

#include "pch.h"
#include <iostream>
int a[101], n;//全局变量，需要在子函数中使用
void quicksort(int left, int right)
{
	int i, j, temp, t;
	if (left > right)//右边的先动，做退出条件
		return;
	temp = a[left];//temp中存储基准数
	i = left;
	j = right;
	while (i != j)
	{
		while (a[j] >= temp && i < j)//右边的大于基准数
			j--;
		while (a[i] <= temp && i < j)//左边的小于基准数
			i++;
		if (i < j)//当哨兵没有相遇
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	a[left] = a[i];
	a[i] = temp;
	quicksort(left, i - 1);
	quicksort(i + 1, right);
}


int main()
{
	int i, j, t;
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++)
		scanf_s("%d", &a[i]);
	quicksort(1, n);

	for (i = 1; i <= n; i++)
		printf_s("%d ", a[i]);


	return 0;
   
}
