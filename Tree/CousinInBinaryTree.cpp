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
pair<int, TreeNode*> one;
pair<int, TreeNode*> two;
void help(TreeNode* root, TreeNode* parent, int k, int val, int flag) {
    if (!root) return;
    if (root->val == val && flag == 1) {
        one = {k, parent};
        return;
    }
    if (root->val == val && flag == 2) {
        two = {k, parent};
        return;
    }
    help(root->left, root, k + 1, val, flag);
    help(root->right, root, k + 1, val, flag);
}
bool isCousins(TreeNode* root, int x, int y) {
    help(root, nullptr, 0, x, 1);
    help(root, nullptr, 0, y, 2);
    return (one.first == two.first) && (one.second != two.second);
}