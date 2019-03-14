

#include "pch.h"
#include <iostream>

int main()
{
	int q[102] = { 0,6,3,1,7,5,8,9,2,4 }, head, tail;
	int i = 0;
	head = 1;
	tail = 10;//9个号码，tail指向末尾的位置加一
	while (head < tail)
	{
		printf_s("%d ", q[head]);
		head++;
		q[tail] = q[head];
		tail++;
		head++;
	}


	return 0;
}
