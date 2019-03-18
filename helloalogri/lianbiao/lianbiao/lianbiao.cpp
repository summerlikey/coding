//链表练习

#include "pch.h"
#include <iostream>
#include <stdlib.h>

/*
int main()
{
	int a = 10;
	int *p;
	p = &a;
	printf_s("\n%d", p);
	a = 11;
	int b = 10;
	//int *p;
	p = &b;
	printf_s("\n%d", p);
	//


	return 0;
}

*////
/*
int main()
{
	int *p;//定义一个指针p
	p = (int *)malloc(sizeof(int));//指针p获取动态分配的内存空间地址
	*p = 10;//向指针p所指向的内存空间存入10
	printf_s("%d", *p);


	return 0;
}

**/


struct node
{

	int data;
	struct node *next;
};

int main()
{
	struct node *head, *p,*q, *t;
	int i, n, a;

	scanf_s("%d", &n);
	head = NULL;//头指针初始为空
	q = NULL;
	for (i = 1; i <= n; i++)
	{
		scanf_s("%d", &a);
		//动态申请一个空间，用来存放一个节点，并用临时指针p指向这个节点
		p = (struct node *)malloc(sizeof(struct node));
		p->data = a;//将数据存储在当前节点的data域中
		p->next = NULL;//设置当前结点的后续指针指向空，也就是当前结点的下一个结点为空
		if (head == NULL)
		{
			head = p;//如果这是第一个创建的结点，则将头指针指向这个结点
		}
		else
		{
			q->next = p;//如果不是第一个创建的结点，则将上一个结点的后继指针指向当前结点
		}

		q = p;//指针q也指向当前啊结点

	}
	t = head;//从头部开始遍历


	scanf_s("%d", &a);//输入待插入的数
	while (t != NULL)//当没有到达链表尾部的时候循环
	{
		if (t->next->data > a)//如果当前结点下一个结点的值大于待插入数，将数插入中间
		{
			p = (struct node*)malloc(sizeof(struct node));//动态申请一个空间，用来存放新增节点
			p->data = a;
			p->next = t->next;//新增结点的后继指针指向当前结点的后结点
			t->next = p;//当前结点的后继指针指向新增结点
			break;
		}
		t = t->next;//继续下一个结点
	}


	//输出链表中的所有数
	t = head;
	while (t != NULL)
	{
		printf_s("%d ", t->data);
		t = t->next;//继续下一个结点
	}
	return 0;
}