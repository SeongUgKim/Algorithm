#include <vector>
using namespace std;

// Brute Force
int maxArea(vector<int>& height) {
    int n = height.size();
    int maxArea = -1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = n - 1; j > i; --j)
        {
            maxArea = max(maxArea, (j - i) * min(height[i], height[j]));
        }
    }
    return maxArea;
}
// Optimal Solution
int solve(vector<int>& height) 
{
    int maxArea = -1;
    int i = 0;
    int j = height.size() - 1;
    while (i < j)
    {
        maxArea = max(maxArea, min(height[i], height[j]) * (j - i));
        height[i] > height[j] ? j-- : i++;
    }
    return maxArea;
}