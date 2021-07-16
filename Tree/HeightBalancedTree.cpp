class Tree {
public:
    int val;
    Tree *left;
    Tree *right;
};
#include <utility>
#include <cmath>
#include <limits>
#include <algorithm>
using namespace std;
pair<bool, int> help(Tree* root) {
    if (!root) return make_pair(true, 0);
    pair<bool, int> right = help(root->right);
    pair<bool, int> left = help(root->left);
    return make_pair(right.first && left.first && abs(right.second - left.second) <= 1, max(right.second, left.second) + 1);
}
bool solve(Tree* root) {
    pair<bool, int> res = help(root);
    return res.first;
}