#include <vector>
using namespace std;
class Tree {
public:
    int val;
    Tree* left;
    Tree* right;
};

void help(Tree* root, vector<int>& vec) {
    if (!root) return;
    if (root->right == nullptr && root->left == nullptr) {
        vec.push_back(root->val);
        return;
    }
    help(root->left, vec);
    help(root->right, vec);
}
bool solve(Tree* root0, Tree* root1) {
    vector<int> zero;
    vector<int> one;
    help(root0, zero);
    help(root1, one);
    if (zero.size() != one.size()) return false;
    for (int i = 0; i < zero.size(); ++i) {
        if (zero[i] != one[i]) return false;
    }
    return true;
}