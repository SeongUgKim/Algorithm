#include <vector>
#include <algorithm>
using namespace std;
int arrayPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int i = 0;
    int n = nums.size();
    int sum = 0;
    while (i < n) {
        sum += nums[i];
        i += 2;
    }
    return sum;
}