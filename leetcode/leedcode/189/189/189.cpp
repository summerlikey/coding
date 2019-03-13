

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> nums;
	int n = 0;
	cin >> n;
	int a = 0;
	int k=0;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		nums.push_back(a);
	}
	cin >> k;

	for (int j = 0; j < k; j++)
	{
		nums.insert(nums.begin(),nums.back());
		nums.pop_back();
	}
	for (int j = 0; j < nums.size(); j++)
	{
		cout << nums[j] << ' ' << endl;
	}
	return 0;
}

