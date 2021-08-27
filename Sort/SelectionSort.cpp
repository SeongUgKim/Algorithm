#include <vector>
using namespace std;
void Swap(int& a, int& b) 
{
    int temp = a;
    a = b;
    b = temp;
}

void SelectionSort(vector<int>& nums) 
{
    int min_index;
    for (int i = 0; i < nums.size(); ++i) 
    {
        min_index = i;
        for (int j = i + 1; j < nums.size(); ++j) 
        {
            if (nums[min_index] > nums[j])
            {
                min_index = j;
            }
        }
        Swap(nums[min_index], nums[i]);
    }
}