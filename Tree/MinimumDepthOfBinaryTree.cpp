class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
};

// Recursive
int minDepth(TreeNode* root) {
    if (root == nullptr)
    {
        return 0;
    }
    if (root->left == nullptr || root->right == nullptr)
    {
        return max(minDepth(root->right), minDepth(root->left)) + 1;
    }
    return min(minDepth(root->left), minDepth(root->right)) + 1;
}


