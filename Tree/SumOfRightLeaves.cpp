class Tree {
public:
    int val;
    Tree* left;
    Tree* right;
};

void helper(int& sum, Tree* root)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->right == nullptr && root->left == nullptr)
    {
        return;
    }
    if (root->right == nullptr)
    {
        helper(sum, root->left);
        return;
    }
    if (root->right->right == nullptr && root->right->left == nullptr)
    {
        sum += root->right->val;
    }
    helper(sum, root->left);
    helper(sum, root->right);
}
int solve(Tree* root) {
    int sum = 0;
    helper(sum, root);
    return sum;
}