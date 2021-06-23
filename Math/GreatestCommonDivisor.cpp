#include "stdc++.h"
using namespace std;

int solve(vector<int>& nums) {
    int dividen;
    int divisor;
    int remainder;
    int comDiv;
    if (nums.size() == 1)
    {
        return nums[0];
    }
    dividen = nums[0];
    divisor = nums[1];
    remainder = dividen % divisor;
    while (remainder != 0)
    {
        dividen = divisor;
        divisor = remainder;
        remainder = dividen % divisor;
    }
    comDiv = divisor;
    for (int i = 1; i < nums.size(); ++i)
    {
        dividen = comDiv;
        divisor = nums[i];
        remainder = dividen % divisor;
        while (remainder != 0)
        {
            dividen = divisor;
            divisor = remainder;
            remainder = dividen % divisor;
        }
        comDiv = divisor;
    }
    return comDiv;
}