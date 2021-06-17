#include <vector>
#include <queue>
using namespace std;
int lastStoneWeight(vector<int>& stones) {
    int zero = 0;
    int n = stones.size();
    int res = 0;
    while (zero < n - 1)
    {
        sort(stones.begin(), stones.end());
        int small = stones[n - 2];
        int large = stones[n - 1];
        stones[n - 2] = 0;
        int diff = large - small;
        stones[n - 1] = diff;
        zero += diff == 0 ? 2 : 1;
    }
    for (int s : stones)
    {
        if (s != 0)
        {
            res = s;
            break;
        }
    }
    return res;
}
int lastStoneWeightWithPriorityQueue(vector<int>& stones) {
    priority_queue<int> pq;
    for (int a : stones)
    {
        pq.push(a);
    }
    int s1;
    int s2;
    while (!pq.empty())
    {
        if (pq.size() == 1)
        {
            return pq.top();
        }
        s1 = pq.top();
        pq.pop();
        s2 = pq.top();
        pq.pop();
        if (s1 != s2)
        {
            pq.push(s1 - s2);
        }
    }
    return 0;
}