#include <vector>
using namespace std;
class Solution {
public:
    int minSwaps(vector<int>& data) {
        int num = 0;
        int n = data.size();
        vector<int> prefix(n + 1);
        for (int i = 1; i <= n; ++i) {
            if (data[i - 1] == 0) prefix[i] = prefix[i - 1] + 1;
            else prefix[i] = prefix[i - 1];
        }
        for (auto d : data) {
            if (d == 1) num++;
        }
        int left = 0;
        int right = num - 1;
        int min_swap = INT_MAX;
        while (right < n) {
            int count = prefix[right + 1] - prefix[left];
            min_swap = min(min_swap, count);
            left++;
            right++;
        }
        return min_swap;
    }
    int minSwapsOptimize(vector<int>& data) {
        int one = 0;
        int n = data.size();
        for (auto d : data) {
            one += d;
        }
        int cnt_one = 0;
        int max_one = 0;
        int left = 0;
        int right = 0;
        while (right < n) {
            cnt_one += data[right++];
            if (right - left > one) {
                cnt_one -= data[left++];
            }
            max_one = max(max_one, cnt_one);
        }
        return one - max_one;
    }
};
