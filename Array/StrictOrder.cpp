#include "stdc++.h"
using namespace std;

bool solve(vector<int>& nums)
{
	if (nums.size() == 0 || nums.size() == 1)
	{
		return true;
	}
	
	if (nums[0] < nums[1])
	{
		for (int i = 0; i < nums.size() - 1;  ++i)
		{
			if (nums[i] >= nums[i + 1])
			{
				return false;
			}
		}
		return true;
	}
	if (nums[0] > nums[1])
	{
		for (int i = 0; i < nums.size() - 1;  ++i)
		{
			if (nums[i] <= nums[i + 1])
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

int main()
{
	vector<int> nums = {1, 0};
	bool result = solve(nums);
	cout << result << endl;
	return 0;
}
