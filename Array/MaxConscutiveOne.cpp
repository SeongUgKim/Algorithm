#include "stdc++.h"
using namespace std;
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int start = 0;
        while (nums[start] == 0)
        {
            start++;
            if (start == nums.size())
            {
                return 0;
            }
        }
        int end = start;
        while (end < nums.size())
        {
            if (nums[end] == 1)
            {
                end++;
            }
            else
            {
                count = max(count, end - start);
                while (nums[end] == 0)
                {
                    end++;
                    if (end == nums.size())
                    {
                        return count;
                    }
                }
                start = end;
            }
        }
        count = max(count, end - start);
        return count;
    }