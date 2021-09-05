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
int getSum(Tree* root) {
    if (!root) return 0;
    return root->val + getSum(root->left) + getSum(root->right);
}
void help(Tree* root, int total) {
    if (!root) return;
    if (!root->left && !root->right) {
        res = max((total - root->val) * root->val, res);
    };
    int left = getSum(root->left);
    int right = getSum(root->right);
    int max_val = max((total - right) * right, (total-left) * left);
    res = max(max_val, res);
    help(root->left, total);
    help(root->right, total); 
}
int solve(Tree* root) {
    int total = getSum(root);
    res = INT_MIN;
    help(root, total);
    return res;
}