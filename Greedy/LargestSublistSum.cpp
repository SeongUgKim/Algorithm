#include <vector>
using namespace std;

int solve(vector<int>& nums) {
	int sum = nums[0];
	int max_val = nums[0];
	for (int i = 1; i < nums.size(); ++i) {
		sum = max(nums[i], nums[i] + sum);
		max_val = max(sum, max_val);
	}
	return max_val;
}
