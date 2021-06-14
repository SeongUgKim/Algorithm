class Tree
{
public:
    int val;
    Tree* left;
    Tree* right;
};

int sum = 0;
void help(Tree* root)
{
    if (root == nullptr)
    {
        return;
    }
    help(root->right);
    sum += root->val;
    root->val = sum;
    help(root->left);
}
Tree* solve(Tree* root) {
    sum = 0;
    help(root);
    return root;
}