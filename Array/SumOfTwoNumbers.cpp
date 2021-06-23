#include "stdc++.h"
using namespace std;

bool solve(vector<int>& nums, int k)
{
	unordered_map<int, int> map;
	for (int a : nums)
	{
		int key = k - a;
		if (map.count(key))
		{
			return true;
		}
		map[a]++;
	}
	return false;
}

int main()
{
	vector<int> nums = {35, 8, 18, 3, 22};
	cout << solve(nums, 11) << endl;
	return 0;
}
