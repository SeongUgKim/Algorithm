#include
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
    vec.push_back(root->val);
    helper(vec, root->left);
    helper(vec, root->right);
}
vector<int> preorderTraversal(TreeNode* root)
{
    vector<int> res;
    helper(res, root);
    return res;
}

