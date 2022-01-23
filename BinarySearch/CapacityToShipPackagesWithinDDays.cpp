#include <vector>
using namespace std;
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int max_capacity = 0;
        int min_capacity = 0;
        int ret_val;
        for (int w : weights) {
            max_capacity += w;
            min_capacity = max(min_capacity, w);
        }
        ret_val = max_capacity;
        while (min_capacity <= max_capacity) {
            int mid = (min_capacity + max_capacity) / 2;
            int required_days = numRequiredDays(weights, mid);
            if (required_days > days) {
                min_capacity = mid + 1;
            } else {
                ret_val = mid;
                max_capacity = mid - 1;
            }
        }
        return ret_val;
        
    }
    
    int numRequiredDays(vector<int>& weights, int capaicty) {
        int required_days = 1;
        int current = 0;
        for (int w : weights) {
            current += w;
            if (current > capaicty) {
                required_days++;
                current = w;
            }
        }
        return required_days;
    }
};
