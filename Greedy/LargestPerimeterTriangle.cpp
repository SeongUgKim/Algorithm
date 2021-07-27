#include <vector>
using namespace std;
int largestPerimeter(vector<int>& nums) {
    int n = nums.size();
    int temp[10000];
    sort(nums.begin(), nums.end());
    temp[0] = nums[0];
    for (int i = 1; i < n; ++i) {
        temp[i] = nums[i] + nums[i - 1];
    }
    for (int i = n - 1; i >= 2; --i) {
        if (temp[i - 1] > nums[i]) return temp[i - 1] + nums[i];
    }
    return 0;
}