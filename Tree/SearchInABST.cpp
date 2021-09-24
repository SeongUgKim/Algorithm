class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* searchBST(TreeNode* root, int val) {
    if (!root) return root;
    if (root->val == val) return root;
    if (root->val < val) return searchBST(root->right, val);
    return searchBST(root->left, val);
}