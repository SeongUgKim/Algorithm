#include <vector>
using namepspace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
void help(TreeNode* root, string s, vector<string>& v)
{
    s += to_string(root->val);
    if (root->left == nullptr && root->right == nullptr)
    {
        v.push_back(s);
        return;
    }
    s += "->";
    if (root->left != nullptr)
    {
        help(root->left, s, v);
    }
    if (root->right != nullptr)
    {
        help(root->right, s, v);
    }

}
vector<string> binaryTreePaths(TreeNode* root)
{
    vector<string> v;
    if (root == nullptr)
    {
        return v;
    }
    string s = "";
    help(root, s, v);
    return v;
}