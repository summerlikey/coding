//买书

#include "pch.h"
#include <iostream>

/*
int main()
{
	int a[1001], i,n,k,t;
	k = 0;
	n = 0;
	t = 0;
	i = 0;
	scanf_s("%d", &n);
	for (i = 1; i <= 1000; i++)
		a[i] = 0;
	for (i = 1; i <= n; i++)
	{
		scanf_s("%d", &t);
		a[t]=1;
	}
	for (i = 1; i <= 1000; i++)
		if (a[i] == 1)
			k++;
	printf_s("%d\n", k);
	for (i = 1; i <= 1000; i++)
		if (a[i] == 1)
			printf_s("%d ", i);
	return 0;
}

*/

//先排序后输出，采用冒泡排序

/*
int main()
{
	int i = 0, j = 0, t = 0, n = 0, a[101];
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++)
		scanf_s("%d", &a[i]);
	for (i = 1; i <= n - 1; i++)
	{	
		for (j = 1; j <= n - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				t=a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
	printf_s("%d ", a[1]);
	for (i = 2; i <= n; i++)
	{
		if (a[i] != a[i - 1])
			printf_s("%d ", a[i]);
	}

	return 0;
}

*/


//使用快速排序
int n = 0;
int a[101];
void quicksort(int left, int right)
{
	int temp = 0;
	int i = 0;
	int j = 0;
	int t = 0;
	if (left > right)
		return;//退出循环
	temp = a[left];
	i = left;
	j = right;
	while (i != j)
	{
		while (a[j] >= temp && i < j)
			j--;
		while (a[i] <= temp && i < j)
			i++;
		if (i < j)
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	a[left] = a[i];
	a[i] = temp;
	quicksort(left, i - 1);
	quicksort(i + 1,right);
}

int main()
{
	int i = 0;
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf_s("%d", &a[i]);
	}
	quicksort(1, n);
	printf_s("%d ", a[1]);
	for (i = 2; i <= n; i++)
	{
		if (a[i] != a[i - 1])
			printf_s("%d ", a[i]);
	}


	return 0;
}