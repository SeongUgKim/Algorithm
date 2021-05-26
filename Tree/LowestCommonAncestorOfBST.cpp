class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root == p || root == q)
    {
        return root;
    }
    TreeNode* t1 = lowestCommonAncestor(root->left, p, q);
    TreeNode* t2 = lowestCommonAncestor(root->right, p, q);
    if (t1 == nullptr && t2 == nullptr)
    {
        return nullptr;
    }
    if (t1 == nullptr)
    {
        return t2;
    }
    if (t2 == nullptr)
    {
        return t1;
    }
    return root;
}

