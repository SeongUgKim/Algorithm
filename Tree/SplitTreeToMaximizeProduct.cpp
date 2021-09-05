#include <climits>
#include <cmath>
using namespace std;
class Tree {
public:
    int val;
    Tree *left;
    Tree *right;
};

int res;
int total;
int getSum(Tree* root) {
    if (!root) return 0;
    return root->val + getSum(root->left) + getSum(root->right);
}
int help(Tree* root) {
    if (!root) return 0;
    int left = help(root->left);
    int right = help(root->right);
    int max_val = max((total - right) * right, (total-left) * left);
    res = max(max_val, res);
    return root->val + left + right;
}
int solve(Tree* root) {
    total = getSum(root);
    res = INT_MIN;
    help(root);
    return res;
}