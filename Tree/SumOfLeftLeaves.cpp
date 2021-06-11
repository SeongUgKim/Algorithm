class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
void help(TreeNode* root, TreeNode* parent, int& sum)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        if (parent == nullptr)
        {
            return;
        }
        if (parent->left == root)
        {
            sum += root->val;
        }
        return;
    }
    help(root->left, root, sum);
    help(root->right, root, sum);
}
int sumOfLeftLeaves(TreeNode* root) {
    int sum = 0;
    int res = 0;
    help(root, nullptr, sum);
    return sum;
}