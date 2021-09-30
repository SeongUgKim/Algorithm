#include <algorithm>
using namespace std;
class Tree {
public:
    int val;
    Tree* left;
    Tree* right;
};

int res;
pair<int, int> help(Tree* root) {
    if (!root) return {0, 0};
    int left = help(root->left).second + 1;
    int right = help(root->right).first + 1;
    res = max(res, left);
    res = max(res, right);
    return {left, right};
}
int solve(Tree* root) {
    res = 0;
    help(root);
    return res;
}