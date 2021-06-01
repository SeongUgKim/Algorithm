class Tree {
public:
    int val;
    Tree* left;
    Tree* right;
};

void helper(Tree* root, int lo, int hi, int& count)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->val >= lo && root->val <= hi)
    {
        count++;
    }
    helper(root->left, lo, hi, count);
    helper(root->right, lo, hi, count);
}
int solve(Tree* root, int lo, int hi) {
    int count = 0;
    helper(root, lo, hi, count);
    return count;
}