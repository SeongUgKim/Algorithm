#include <climits>
class Solution {
public:
    // input: root of binary search tree and target value
    // output: value in tree that is closest to the target
    // example input [4, 2, 5, 1, 3] , target = 3.8
    // example output 4
    pair<double, int> closest;
    void dfs(TreeNode* root, double target) {
        if (!root) return;
        if (double(root->val) == target) {
            closest.first = 0.0;
            closest.second = root->val;
            return;
        }
        if (abs(root->val - target) < closest.first) {
            closest.first = abs(root->val - target);
            closest.second = root->val;
        }
        if (root->val > target) dfs(root->left, target);
        else dfs(root->right, target);
    }
    int closestValue(TreeNode* root, double target) {
        closest.first = DBL_MAX;
        closest.second = INT_MAX;
        dfs(root, target);
        return closest.second;
    }
    
    int closestValue2(TreeNode* root, double target) {
        int a = root->val;
        TreeNode* kid = target < a ? root->left : root->right;
        if (!kid) return a;
        int b = closestValue(kid, target);
        return abs(a - target) < abs(b - target) ? a : b;
    }
};
