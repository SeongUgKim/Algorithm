class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr)
    {
        return nullptr;
    }
    TreeNode* temp = root->right;
    root->right = root->left;
    root->left = temp;
    invertTree(root->right);
    invertTree(root->left);
    return root;
}