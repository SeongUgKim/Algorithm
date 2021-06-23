//
//  TwoSumSortedList.cpp
//  Algorithm
//
//  Created by Seong Kim on 2021/03/22.
//  Copyright © 2021 Seong Kim. All rights reserved.
//
#include <vector>
using namespace std;
bool TwoSumSortedList(vector<int>& nums, int k) {
    int i = 0;
    size_t j = nums.size() - 1;
    while (i < j)
    {
        if (nums[i] + nums[j] > k)
        {
            j--;
        }
        else if (nums[i] + nums[j] < k)
        {
            i++;
        }
        else
        {
            return true;
        }
    }
    return false;
}
