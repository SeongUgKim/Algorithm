class Tree
{
public:
    int val;
    Tree* left;
    Tree* right;
};
int help(Tree* root, Tree* parent, Tree* grandParent)
{
    if (root == nullptr)
    {
        return 0;
    }
    if (parent == nullptr || grandParent == nullptr)
    {
        return help(root->left, root, parent) + help(root->right, root, parent);
    }
    if (grandParent->val % 2 == 0)
    {
        return help(root->left, root, parent) + help(root->right, root, parent) + root->val;
    }
    return help(root->left, root, parent) + help(root->right, root, parent);
}
int solve(Tree* root) {
    return help(root, nullptr, nullptr);
}