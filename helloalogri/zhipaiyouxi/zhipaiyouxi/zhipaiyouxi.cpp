

#include "pch.h"
#include <iostream>


struct queue
{
	int data[1000];
	int head;
	int tail;
};
struct stack
{
	int data[10];
	int top;
};


int main()
{
	int i,t,flag;
	struct queue q1, q2;
	struct stack s;
	//初始化q1，q2队列，最开始时两人手中没有牌
	q1.head = 1;
	q1.tail = 1;
	q2.head = 1;
	q2.tail = 1;
	//初始化栈，最开始时桌面上美誉牌
	s.top = 0;
	//读入最初手中的牌，q1和q2分别读取
	for (i = 1; i <= 6; i++)
	{
		scanf_s("%d", &q1.data[q1.tail]);
			q1.tail++;

	}
	for (i = 1; i <= 6; i++)
	{
		scanf_s("%d", &q2.data[q2.tail]);
		q2.tail++;
	}
	while (q1.head < q1.tail&&q2.head < q2.tail)
	{
		//q1先出牌，
		t = q1.data[q1.head];
		flag = 0;
		for (i = 1; i <= s.top; i++)
		{
			if (t == s.data[i])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			q1.head++;
			s.top++;
			s.data[s.top] = t;
		}

		else
		{
			q1.head++;
			q1.data[q1.tail] = t;
			q1.tail++;
			while (s.data[s.top] != t)
			{
				q1.data[q1.tail] = s.data[s.top];
				q1.tail++;
				s.top--;
			}
		}

		t = q2.data[q2.head];
		flag = 0;
		for (i = 0; i <= s.top; i++)
		{
			if (t == s.data[i])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			q2.head++;
			s.top++;
			s.data[s.top] = t;
		}
		else
		{
			q2.head++;
			q2.data[q2.tail] = t;
			q2.tail++;
			while (s.data[s.top] != t)
			{
				q2.data[q2.tail] = s.data[s.top];
				q2.tail++;
				s.top--;
			}
		}

	}
	if (q2.head == q2.tail)//q1获胜
	{
		printf_s("小哼win\n");
		printf_s("小哼当前手中的牌时");
		for (i = q1.head; i <= q1.tail - 1; i++)
			printf_s("%d", q1.data[i]);
		if (s.top > 0)//如果桌上有牌则输出桌上的牌
		{
			printf_s("\n桌上的牌时");
			for (i = 1; i <= s.top; i++)
				printf_s("%d", s.data[i]);
		}
		else
			printf_s("\n桌上已经没有牌了");
	}
	if (q1.head == q1.tail)
	{
		printf_s("q2获胜\n");
		printf_s("q2中的牌是");
		for (i = q2.head; i <= q2.tail - 1; i++)
			printf_s("%d", q2.data[i]);
		if (s.top > 0)//桌上还有牌
		{
			printf_s("桌上的牌是\n");
			for (i = 1; i <= s.top; i++)
				printf_s(" %d", s.data[i]);
		}
		else
			printf_s("\n桌上已经没有牌了");
	}

	return 0;
}

