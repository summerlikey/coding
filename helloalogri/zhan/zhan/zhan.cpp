//



//栈和队列不同，后进后出，就像放在水桶里面的东西一样，需要先把上面的东西拿掉

#include "pch.h"
#include <iostream>
#include<stdio.h>
#include<string.h>

int main()
{
	char a[101], s[101];
	int i, len, mid, next, top;
	gets_s(a);//读入一串字符串
	len = strlen(a);
	mid = len / 2 - 1;//求字符串的中点

	top = 0;//栈的初始化
	//将mid前的字符依次入栈
	for (i = 0; i <= mid; i++)
	{
		s[++top] = a[i];
	}
	//判断字符串的长度是奇数还是偶数，并找出需要进行字符匹配的起始下标
	if (len % 2 == 2)
		next = mid + 1;
	else
		next = mid + 2;
	//开始匹配
	for (i = next; i <= len - 1; i++)
	{
		if (a[i] != s[top])
			break;
		top--;
	}
	if (top == 0)
		printf_s("YES");
	else
		printf_s("NO");

	return 0;


}

