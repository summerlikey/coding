
#include "pch.h"
#include <iostream>

int main()
{
	int a[100] = { 0 };
	int i, j, t = 0;
	for (i = 0; i < 5; i++)
		scanf_s("%d", &a[i]);
	for(i=4;i>=0;i--)
		for(j=4;j>0;j--)
			if (a[i] < a[j])
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}

	for (i = 0; i < 5; i++)
		printf_s("%d ", a[i]);


	return 0;
}

