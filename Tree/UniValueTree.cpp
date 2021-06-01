class Tree {
public:
    int val;
    Tree* left;
    Tree* right;
};

bool helper(int value, Tree* root)
{
    if (root == nullptr)
    {
        return true;
    }
    bool flag = root->val == value;
    return flag && helper(value, root->left) && helper(value, root->right);
}
bool solve(Tree* root) {
    return helper(root->val, root);
}