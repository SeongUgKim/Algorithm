#include <vector>
using namespace std;
bool solve(vector<int>& nums) {
    int n = nums.size();
    unordered_set<int> st;
    for (int num : nums) {
        st.insert(num * num);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (st.count(nums[i] * nums[i] + nums[j] * nums[j])) return true;
        }
    }
    return false;
}