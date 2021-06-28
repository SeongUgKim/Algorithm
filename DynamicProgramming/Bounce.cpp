#include <unordered_set>
#include <vector>
using namespace std;
//dp[i] = i번째 index에 있을때 last index에 도달할 수 있는가
unordered_set<int> st;
vector<int> dp;
int topdown(vector<int>& nums, int k) {
    if (st.count(k)) return 0;
    st.insert(k);
    int n = nums.size();
    if (k < 0 || k >= n) return 0;
    if (k == n - 1) return 1;
    if (dp[k] != -1) return dp[k];
    return dp[k] = topdown(nums, k - nums[k]) || topdown(nums, k + nums[k]);
}
bool solve(vector<int>& nums, int k) {
    dp = {};
    int n = nums.size();
    dp.resize(n, -1);
    st.clear();
    return topdown(nums, k);
}