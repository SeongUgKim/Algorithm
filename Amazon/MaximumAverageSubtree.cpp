/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
*/

#include <utilize>
using namespace std;

class Solution {
public:
    double max_avg = INT_MIN;
    pair<int, int> findSumAndNumber(TreeNode* root) {
        if (!root) return {0, 0};
        if (!root->right && !root->left) {
            max_avg = max(max_avg, static_cast<double>(root->val));
            return {root->val, 1};
        }
        auto left = findSumAndNumber(root->left);
        auto right = findSumAndNumber(root->right);
        int sum = left.first + right.first + root->val;
        int num = left.second + right.second + 1;
        double avg = static_cast<double>(sum) / static_cast<double>(num);
        max_avg = max(max_avg, avg);
        return {sum, num};
    }
    double maximumAverageSubtree(TreeNode* root) {
        auto res = findSumAndNumber(root);
        return max_avg;
    }
};
