#include <vector>
using namespace std;

class Tree {
public:
    int val;
    Tree* left;
    Tree* right;
};

vector<int> res;
void help(Tree* root, int level) {
    if (root == nullptr) return;
    if (res.size() < level + 1) res.push_back(root->val);
    else res[level] += root->val;
    help(root->right, level);
    help(root->left, level + 1);
}
vector<int> solve(Tree* root) {
    res.clear();
    help(root, 0);
    return res;
}