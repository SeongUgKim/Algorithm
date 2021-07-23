#include <utility>
using namespace std;
class Tree {
public:
    int val;
    Tree* left;
    Tree* right;
};
pair<int, bool> help(Tree* root) {
    if (! root) return {0, true};
    if (root->right == nullptr && root->left == nullptr) return {1, true};
    bool flag;
    if (root->right == nullptr) flag = root->val == root->left->val;
    else if (root->left == nullptr) flag = root->val == root->right->val;
    else flag = root->val == root->right->val && root->val == root->left->val;
    pair<int, bool> right = help(root->right);
    pair<int, bool> left = help(root->left);
    bool res = (flag && right.second) && left.second;
    return {right.first + left.first + res, res};
}
int solve(Tree* root) {
    pair<int, bool> res = help(root);
    return res.first;
}
