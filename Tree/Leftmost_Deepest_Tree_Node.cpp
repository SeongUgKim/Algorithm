#include <utility>
using namespace std;

class Tree {
public:
	int val;
	Tree* left;
	Tree* right;
};

pair<int, int> help(Tree* root, int depth) {
    if (!root->left && !root->right) return {root->val, depth};
    if (!root->left) return help(root->right, depth + 1);
    if (!root->right) return help(root->left, depth + 1);
    pair<int, int> left = help(root->left, depth + 1);
    pair<int, int> right = help(root->right, depth + 1);
    if (left.second == right.second) return left;
    return left.second > right.second ? left : right;
}
int solve(Tree* root) {
    pair<int, int> node = help(root, 0);
    return node.first;
}
