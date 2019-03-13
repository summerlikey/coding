

#include "pch.h"
#include <iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int a[11] = { 0 }, i = 0, j = 0,t=0;
	for (int i = 0; i < 5; i++)
	{
		scanf_s("%d", &t);
		a[t]++;
	}
	for (int i = 10; i >=0; i--)
	{
		for (int j = 0; j < a[i]; j++)
		{
			printf_s("%d", i);
		}
	}

	return 0;

}

