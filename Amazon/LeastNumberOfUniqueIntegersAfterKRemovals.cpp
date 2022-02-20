#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int, int> count;
        map<int, int> sorted;
        for (auto i : arr) {
            count[i]++;
        }
        priority_queue<pair<int, int>> pq;
        for (auto& c : count) {
            pq.push({c.second * -1, c.first});
        }
        int res = count.size();
        while (k) {
            auto p = pq.top();
            pq.pop();
            if ((p.first + 1) == 0) {
                res--;
                k--;
                continue;
            }
            pq.push({p.first + 1, p.second});
            k--;
        }
        return res;
    }
    struct compare {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        }  
    };
    
    int findLeastNumOfUniqueIntsUsingSort(vector<int>& arr, int k) {
        unordered_map<int, int> count;
        for (auto i : arr) {
            count[i]++;
        }
        vector<pair<int, int>> temp;
        for (auto& c : count) {
            temp.push_back({c.first, c.second});
        }
        sort(temp.begin(), temp.end(), compare());
        
        auto it = temp.begin();
        int res = temp.size();
        while (it != temp.end() && k-- > 0) {
            it->second--;
            if (it->second == 0) {
                it++;
                res--;
            }
        }
        return res;
    }
};
