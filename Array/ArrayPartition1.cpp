#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int arrayPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int first = 0;
    int second = first + 1;
    int sum = 0;
    while (first < nums.size() - 1) {
        sum += min(nums[first], nums[second]);
        first += 2;
        second += 2;
    }
    return sum;
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(2);
    cout << arrayPairSum(nums) << endl;
}