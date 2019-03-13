

#include "pch.h"
#include <iostream>
#include <stdint.h>
using namespace std;
int main()
{
	uint32_t n;
	n = 1011;
	uint32_t result = 101;
//	int a = 0;
//	a=sizeof(uint32_t);
	for (int i = 0; i < 32; ++i)
	{
		result = (result << 1) + (n >> i & 1);
		
	}

//	cout << a;
	cout << result;
}
