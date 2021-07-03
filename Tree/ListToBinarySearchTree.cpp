class Tree {
public:
    int val;
    Tree* left;
    Tree* right;
    Tree(int a) {
        val = a;
        left = nullptr;
        right = nullptr;
    }
};

#include <vector>
using namespace std;

Tree* help(vector<int>& nums, int start, int end) {
    if (start > end) return nullptr;
    int mid = start + (end - start + 1) / 2;
    Tree* result = new Tree(nums[mid]);
    result->right = help(nums, mid + 1, end);
    result->left = help(nums, start, mid - 1);
    return result;
}
Tree* solve(vector<int>& nums) {
    return help(nums, 0, nums.size() - 1);
}