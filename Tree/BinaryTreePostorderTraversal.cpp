#include <vector>
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
};

void helper(vector<int>& vec, TreeNode* root)
{
    if (root == nullptr)
    {
        return;
    }
    helper(vec, root->left);
    helper(vec, root->right);
    vec.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    helper(res, root);
    return res;
}
