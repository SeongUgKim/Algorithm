#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = nums[0] + nums[1] + nums[2];
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int first = 0; first < nums.size() - 2; ++first) {
            if (first > 0 && nums[first] == nums[first - 1]) continue;
            int second = first + 1;
            int third = n - 1;
            while (second < third) {
                int currSum = nums[first] + nums[second] + nums[third];
                if (currSum == target) return currSum;
                if (abs(target - currSum) < abs(target - closest)) closest = currSum;
                if (currSum > target) third--;
                if (currSum < target) second++;
            }
        }
        return closest;
    }
};
