#include <cmath>
using namespace std;

class Tree {
public:
    int val;
    Tree* left;
    Tree* right;
};

int help(Tree* root, bool flag) {
    if (!root) return 0;
    // if ture -> two ways : 1. use, 2: not use
    if (flag) {
        int a = root->val + help(root->left, false) + help(root->right, false);
        int b = help(root->left, true) + help(root->right, true);
        return max(a, b);
    }
    // if false -> do not use
    return help(root->left, true) + help(root->right, true);
}
int solve(Tree* root) {
    return help(root, true);
}