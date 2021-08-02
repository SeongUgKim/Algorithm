#include <cmath>
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
};

int sum;
int help(TreeNode* root) {
    if (!root) return 0;
    int right = help(root->right);
    int left = help(root->left);
    sum += abs(right - left);
    return root->val + right+ left;
}
int findTilt(TreeNode* root) {
    sum = 0;
    help(root);
    return sum;
}