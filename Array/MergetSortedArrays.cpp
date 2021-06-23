#include "stdc++.h"
using namespace std;

void merge(vector<int> nums1, int m, vector<int> nums2, int n)
{
    /*int a = 0;
    for (int i = m; i < n + m; ++i)
    {
        nums1[i] = nums2[a++];
    }
    sort(nums1.begin(), nums1.end());*/
    /*int tail1 = m - 1;
    int tail2 = n - 1;
    int finish = m + n - 1;
    while (tail1 >= 0 && tail2 >= 0)
    {
        nums1[finish--] = (nums1[tail1] > nums2[tail2]) ? nums1[tail1--] : nums2[tail2--];
    }
    while (tail2 >= 0)
    {
        nums1[finish--] = nums2[tail2--];
    }*/

    int a = m - 1;
    int b = n - 1;
    int end = nums1.size() - 1;
    while (a >= 0 && b >= 0)
    {
        nums1[end--] = nums1[a] > nums2[b] ? nums1[a--] : nums2[b--];
    }
    while (b >= 0)
    {
        nums1[end--] = nums2[b--];
    }

}
