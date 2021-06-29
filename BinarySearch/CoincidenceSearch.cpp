#include <vector>
using namespace std;
int topdown(vector<int>& nums, int l, int r, int left_bound, int right_bound){
    if(l>r) return 0;
    int m = (l+r)/2;
    return (nums[m]>=left_bound && nums[m]<=right_bound) + topdown(nums,l,m-1,left_bound,min(right_bound,nums[m])) + topdown(nums,m+1,r,max(left_bound,nums[m]),right_bound);
}

int solve(vector<int>& nums) {
    int n = nums.size();
    return topdown(nums,0,n-1,INT_MIN,INT_MAX);
}

// brute force
int bruteForce(vector<int>& nums) {
    int n = nums.size();
    int visited[n];
    int count = 0;
    for (int i = 0; i < n; ++i) {
        memset(visited, 0, sizeof(visited));
        int lo = 0;
        int hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] == nums[i]) {
                count++;
                break;
            }
            if (visited[mid] == 1 || mid < 0 || mid >= n) break;
            if (nums[mid] < nums[i]) lo = mid + 1;
            else hi = mid - 1;
            visited[mid] = 1;
        }
    }
    return count;
}