class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
};

bool hasPathSum(TreeNode* root, int targetSum)
{
    if (root == nullptr)
    {
        return false;
    }
    if (root->right == nullptr && root->left == nullptr && targetSum - root->val == 0)
    {
        return true;
    }
    if (root->right == nullptr)
    {
        return hasPathSum(root->left, targetSum - root->val);
    }
    if (root->left == nullptr)
    {
        return hasPathSum(root->right, targetSum - root->val);
    }
    return hasPathSum(root->right, targetSum - root->val) || hasPathSum(root->left, targetSum - root->val);
}

