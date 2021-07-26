#include <vector>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int max_val;
int help(TreeNode* root) {
    if (!root) return 0;
    int left = help(root->left);
    int right = help(root->right);
    max_val = max(max_val, left + right);
    return max(left, right) + 1;
}
int diameterOfBinaryTree(TreeNode* root) {
    help(root);
    return max_val;
}