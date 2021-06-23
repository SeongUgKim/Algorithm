/*#include <vector>
#include <unordered_set>
#include <iostream>
#include <algorithm>
using namespace std;*/
#include "stdc++.h"
using namespace std;
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
{
    //sort and two points
    vector<int> res;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    size_t i = 0;
    size_t j = 0;
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] == nums2[j])
        {
            res.push_back(nums1[i]);
            i++;
            j++;
        }
        else if (nums1[i] > nums2[j])
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    return res;
    //unordered_map
    /*unordered_map<int, int> map;
    vector<int> res;
    for (int num : nums1)
    {
        map[num]++;
    }
    for (int num : nums2)
    {
        if (map[num]-- > 0)
        {
            res.push_back(num);
        }
    }
    return res;*/
}

int main()
{
    vector<int> nums1;
    nums1.push_back(4);
    nums1.push_back(9);
    nums1.push_back(5);
    vector<int> nums2;
    nums2.push_back(9);
    nums2.push_back(4);
    nums2.push_back(9);
    nums2.push_back(8);
    nums2.push_back(4);
    vector<int> result = intersect(nums1, nums2);
    for (int num : result)
    {
        cout << num << endl;
    }
}