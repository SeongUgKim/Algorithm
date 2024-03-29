#include <vector>
using namespace std;
// topdown
int dp[396][396];
int topdown(vector<int>& days, vector<int>& costs, int i, int cur) {
int dp[400][400];
    int topdown(vector<int>& days, vector<int>& costs, int next, int index) {
        int n = days.size();
        if (index == n) return 0;
        int& res = dp[next][index];
        if (res != -1) return res;
        if (next > days[index]) return res = topdown(days, costs, next, index + 1);
        return res = min(costs[0] + topdown(days, costs, days[index] + 1, index + 1), min(costs[1] + topdown(days, costs, days[index] + 7, index + 1), costs[2] + topdown(days, costs, days[index] + 30, index + 1)));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs)    if (i == days.size()) return 0;
    if (dp[i][cur] != -1) return dp[i][cur];
    if (days[i] < cur) return dp[i + 1][cur] = topdown(days, costs, i + 1, cur);
    int one_day = dp[i + 1][cur] = topdown(days, costs, i + 1, days[i] + 1) + costs[0];
    int seven_days = dp[i + 1][cur] = topdown(days, costs, i + 1, days[i] + 7) + costs[1];
    int thirty_days = dp[i + 1][cur] =topdown(days, costs, i + 1, days[i] + 30) + costs[2];
    return min(one_day, min(seven_days, thirty_days));
}
int mincostTickets(vector<int>& days, vector<int>& costs) {
    memset(dp, -1, sizeof(dp));
    return topdown(days, costs, 0, 1);
}

// bottom-up (optimization)

int mincostTickets(vector<int>& days, vector<int>& costs) {
    int n = days.size();
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[n] = 0;
    for (int i = n - 1; i >= 0; --i) {
        int d7 = i, d30 = i;
        while (d7 < n && days[d7] < days[i] + 7) d7++;
        while (d30 < n && days[d30] < days[i] + 30) d30++;
        dp[i] = min({costs[0] + dp[i + 1], costs[1] + dp[d7], costs[2] + dp[d30]});
    }
    return dp[0];        
}

