class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
};

bool helper(TreeNode* p, TreeNode* q)
{
    if (p == nullptr && q == nullptr)
    {
        return true;
    }
    if (p == nullptr || q == nullptr)
    {
        return false;
    }
    return (p->val == q->val) && helper(p->left, q->right) && helper(p->right, q->left);
}
bool isSymmetric(TreeNode* root)
{
    return helper(root->right, root->left);
}
