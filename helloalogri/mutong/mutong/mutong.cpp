
#include "pch.h"
#include <iostream>


/*
int main()
{
	using namespace std;
	int a[11], i, j, t;
	for (i = 0; i <= 10; i++)
		a[i] = 0;  //初始化为0
	for (i = 1; i <= 5; i++)
	{
		scanf_s("%d", &t);
		a[t]++;
	}
	for (i = 10; i >= 0; i--)
		for (j = 1; j <= a[i]; j++)
			printf_s("%d", i);

	return 0;
}
*/


///如果是一千个数，则需要1001个桶
/*
int main()
{
	int book[1001], i, j, t,n;
	for (i = 0; i <= 1000; i++)
		book[i] = 0;
	scanf_s("%d", &n);
	for (i = 0; i <= n; i++)
	{
		scanf_s("%d", &t);
		book[t]++;
	}
	for (i = 1000; i >= 0; i--)
		for (j = 1; j <= book[i]; j++)
			printf_s("%d ", i);


	return 0;
}
*/
//maopaopaixu

int main()
{
	int a[100], i, j, t,n;
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++)
		scanf_s("%d", &a[i]);
	for(i=1;i<=n-1;i++)
		for (j = 1; j <= n - i; j++)
		{
			if (a[j] < a[j + 1])
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	for (i = 1; i <= n; i++)
		printf_s("%d ", a[i]);

	return 0;
}


