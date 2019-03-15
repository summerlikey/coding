//队列的描述
/*

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

*/


//队列的实现,先进先出

#include "pch.h"
#include <iostream>
struct queue //利用结构体实现队列
{
	int data[100];//队列主体，存储内容
	int head;//队首
	int tail;//队尾


};
int main()
{
	struct queue q;
	int i = 0;
	//初始化序列
	q.head = 1;
	q.tail = 1;
	for (i = 1; i <= 9; i++)
	{
		//依此插入9个数
		scanf_s("%d", &q.data[q.tail]);
		q.tail++;//队尾比数据多一个
	}

	while (q.head < q.tail)//当队列不为空的时候执行循环
	{
		//打印队首，并将队首出列
		printf_s("%d ", q.data[q.head]);
		q.head++;

		//新队首添加到队尾，也就是第二个
		q.data[q.tail] = q.data[q.head];
		q.tail++;
		q.head++;
	}


	return 0;
}