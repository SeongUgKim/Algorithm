#include <unordered_set>
#include "stdc++.h"
using namespace std;

    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //Boolean array;
        /*vector<bool> a(nums.size(), false);
        for (int n : nums)
        {
            a[n - 1] = true;
        }
        vector<int> ret;
        for (int i = 0; i < a.size(); ++i)
        {
            if (a[i] == false)
            {
                ret.push_back(i + 1);
            }
        }
        return ret;
        */
        // without extra space
        /*
        vector<int> ret;
        for (int i = 0; i < nums.size(); ++i)
        {
            int curr = abs(nums[i]);
            nums[curr - 1] = abs(nums[curr - 1]) * -1;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > 0)
            {
                ret.push_back(i + 1);
            }
        }
        return ret;*/
        // HashSet
        vector<int> ret;
        unordered_set<int> st;
        for (int i : nums)
        {
            st.insert(i);
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (!st.count(i + 1))
            {
                ret.push_back(i + 1);
            }
        }
        return ret;
    }