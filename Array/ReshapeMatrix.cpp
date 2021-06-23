#include "stdc++.h"
using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c)
{
    int sum = 0;
    for (int i = 0; i < (int)nums.size(); ++i)
    {
        sum += nums[i].size();
    }
    if (sum != r * c)
    {
        return nums;
    }
    vector<int> temp;
    for (int i = 0; i < (int) nums.size(); ++i)
    {
        for (int j = 0; j < (int)nums[i].size(); ++j)
        {
            temp.push_back(nums[i][j]);
        }
    }
    int k = 0;
    vector<vector<int>> ret(r, vector<int>(c, 0));
    for (int i = 0; i < r;  ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            ret[i][j] = temp[k++];
        }
    }
    return ret;
}

int main()
{
    vector<vector<int>> nums;
    vector<int> l1;
    vector<int> l2;
    l1.push_back(1);
    l1.push_back(2);
    l2.push_back(3);
    l2.push_back(4);
    nums.push_back(l1);
    nums.push_back(l2);
    vector<vector<int>> res = matrixReshape(nums, 1, 4);
    return 0;
}