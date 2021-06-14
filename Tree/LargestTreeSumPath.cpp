class Tree
{
public:
    int val;
    Tree* left;
    Tree right;
};

int dfs(Tree* root, int& ans)
{
    if (root == nullptr)
    {
        return 0;
    }
    int left = dfs(root->left, ans);
    int right = dfs(root->right, ans);
    int sumWithBothChildren = left + right + root->val;
    int sumWithSingleChildOrAlone = max(max(left, right) + root->val, root->val);
    int realMax = max(sumWithBothChildren, sumWithSingleChildOrAlone);
    ans = max(ans, realMax);
    return sumWithSingleChildOrAlone;
}
int solve(Tree* root) {
    int ans = 0;
    dfs(root, ans);
    return ans;
}
