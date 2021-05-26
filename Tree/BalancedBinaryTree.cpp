class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
};

int countLevel(TreeNode* root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int left = countLevel(root->left) + 1;
    int right = countLevel(root->right) + 1;
    return max(left, right);
}
bool isBalanced(TreeNode* root) {
    if (root == nullptr)
    {
        return true;
    }
    int diff = abs(countLevel(root->right) - countLevel(root->left));
    if (diff > 1)
    {
        return false;
    }
    return  isBalanced(root->left) && isBalanced(root->right);
}


