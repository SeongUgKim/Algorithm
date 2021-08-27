#include <vector>
using namespace std;

void Swap(vector<int>& nums, int a, int b) 
{
    int temp = nums[a];
    nums[a] = nums[b];
    nums[b] = temp;
}

int Partition(vector<int>& nums, int left, int right) 
{
    int pivot = nums[right];
    int i = (left - 1);
    for (int j = left; j < right; ++j) 
    {
        if (nums[j] < pivot) 
        {
            i++;
            Swap(nums, i, j);
        }
    }
    int pivotPos = i + 1;
    Swap (nums, pivotPos, right);
    return pivotPos;
}

void QuickSortRecursive(vector<int>& nums, int left, int right) 
{
    if (left >= right)
    {
        return;
    }

    int pivotPos = Partition(nums, left, right);
    QuickSortRecursive(nums, left, pivotPos - 1);
    QuickSortRecursive(nums, pivotPos + 1, right);
}

void QuickSort(vector<int>& nums) 
{
    QuickSortRecursive(nums, 0, nums.size() - 1);
}