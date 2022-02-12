#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int i = 0;
        int j = i + 1;
        int n = arr.size();
        vector<vector<int>> ans;
        int min_value = INT_MAX;
        while (j < n) {
            int diff = arr[j] - arr[i];
            if (diff < min_value) {
                min_value = diff;
                vector<int> temp(2);
                temp[0] = arr[i];
                temp[1] = arr[j];
                ans.clear();
                ans.push_back(temp);
            }
            else if (diff == min_value) {
                vector<int> temp(2);
                temp[0] = arr[i];
                temp[1] = arr[j];
                ans.push_back(temp);
            }
            i++;
            j = i + 1;
        }
        return ans;
    }
};
