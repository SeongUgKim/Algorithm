#include <vector>
using namespace std;

void InsertionSort(vector<int> nums) 
{
    int key;
    for (int i = 0; i < nums.size(); ++i) 
    {
        key = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > key) 
        {
            nums[j + 1] = nums[j];
            j = j - 1;
        }
        nums[j + 1] = key;
    }
}