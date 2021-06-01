class Tree {
public:
    int val;
    Tree* left;
    Tree* right;
};
void inorder(int& a, Tree* root)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(a, root->left);
    a += root->val;
    inorder(a, root->right);
}
int solve(Tree* root) {
    int a = 0;
    inorder(a, root);
    return a;
}