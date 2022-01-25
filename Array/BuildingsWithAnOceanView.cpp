#include <vector>
#include <stack>
#include <algorith>
#include <utility>
using namespace std;
class Solution {
public:
    // input : height of buildings -> vector<int>& heights
    // output: a list of indices of buildings that have an ocean view in ascending order -> vector<int>
    // limit -> right of all buildings
    
    // scan the heights array in backward.
    // from the end of the array, remember the maximum height of the building
    // compare current index's building's height and the maximum height
    // if current building is taller than maximum height-> update max height and result vectors
    // after finishing the scanning, sort the result array-> return.
    
    vector<int> findBuildings(vector<int>& heights) {
        vector<pair<int, int>> res;
        int n = heights.size();
        int max_height = heights[n - 1];
        res.push_back({heights[n - 1], n - 1});
        for (int i = n - 1; i >= 0; --i) {
            if (heights[i] > max_height) {
                max_height = heights[i];
                res.push_back({heights[i], i});
            }
        }
        vector<int> ret(res.size());
        sort(res.begin(), res.end());
        reverse(res.begin(), res.end());
        for (int i = 0; i < res.size(); ++i) {
            ret[i] = res[i].second;
        }
        return ret;
		}
		vector<int> findBuildingsOptimized(vector<int>& heights) {
        vector<int> res;
        int n = heights.size();
        int max_height = heights[n - 1];
        res.push_back(n - 1);
        for (int i = n - 2; i >= 0; --i) {
            if (heights[i] > max_height) {
                max_height = heights[i];
                res.push_back(i);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
		vector<int> MonotomicStack(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans;
        stack<int> st;
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && heights[st.top()] < heights[i]) {
                st.pop();
            }
            if (st.size() == 0) ans.push_back(i);
            st.push(i);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
