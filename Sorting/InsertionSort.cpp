#include "stdc++.h"
using namespace std;

void insertionSort(vector<int>& nums)
{
    int n = nums.size();
    for (int i = 1; i < n; ++i)
    {   
        int key = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > key)
        {
            nums[j + 1] = nums[j];
            j = j - 1;
        }
        nums[j + 1] = key;
    }
}

int main()
{
    vector<int> nums = {9, 7, 3, 6, 2};
    insertionSort(nums);
    for (int a : nums)
    {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}