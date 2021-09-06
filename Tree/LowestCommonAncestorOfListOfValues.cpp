#include <vector>
#include <unordered_set>
using namespace std;

class Tree {
public:
    int val;
    Tree* left;
    Tree* right;
};

Tree* help(Tree* root, unordered_set<int>& st) {
    if (!root) return root;
    if (st.find(root->val) != st.end()) return root;
    Tree* left = help(root->left, st);
    Tree* right = help(root->right, st);
    if (left && right) return root;
    return left ? left : right;
}
Tree* solve(Tree* root, vector<int>& values) {
    unordered_set<int> st (values.begin(), values.end());
    return help(root, st);
}