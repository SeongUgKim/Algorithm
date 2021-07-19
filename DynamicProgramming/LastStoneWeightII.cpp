#include <unordered_map>
#include <vector>
using namespace std;

vector<unordered_map<int, int>> dp;
int topdown(vector<int>& stones, int index, int sum) {
    if (index == stones.size()) return sum < 0 ? 101 : sum;
    if (dp[index].find(sum) != dp[index].end()) return dp[index][sum];
    int add = dp[index + 1][sum + stones[index]] = topdown(stones, index + 1, sum + stones[index]);
    int sub = dp[index + 1][sum - stones[index]] = topdown(stones, index + 1, sum - stones[index]);
    return min(add, sub);
}
int lastStoneWeightII(vector<int>& stones) {
    dp.clear();
    int n = stones.size();
    dp.resize(31);
    return topdown(stones, 0, 0);
}