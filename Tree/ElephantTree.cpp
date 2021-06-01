class Tree {
public:
    int val;
    Tree* left;
    Tree* right;
};

Tree* solve(Tree* root) {
    if (root == nullptr)
    {
        return nullptr;
    }
    root->left = solve(root->left);
    root->right = solve(root->right);
    if (root->left == nullptr && root->right == nullptr)
    {
        root->val = root->val;
    }
    else if (root->left == nullptr)
    {
        root->val += root->right->val;
    }
    else if (root->right == nullptr)
    {
        root->val += root->left->val;
    }
    else
    {
        root->val = root->val + root->left->val + root->right->val;
    }
    return root;
}