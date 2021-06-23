#include <vector>
#include <iostream>
using namespace std;
int removeDuplicates(vector<int>& nums)
{
    int c = 1;
    for (int i = 1; i < nums.size(); ++i) 
    {
        if (nums[i] != nums[i - 1])
        {
            nums[c++] = nums[i];
        }
    }
    return c;
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    cout << removeDuplicates(nums) << endl;
}
