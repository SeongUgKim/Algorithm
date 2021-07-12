#include <vector>
using namespace std;

class Tree {
public:
    int val;
    Tree* left;
    Tree* right;
    Tree(int value)
    {
        val = value;
    }
};
int i = 0;
Tree* help(vector<int>& preorder, vector<int>& inorder) {
    if (inorder.size() == 0) {
        i--;
        return nullptr;
    }
    if (inorder.size() == 1) {
        Tree* res = new Tree(inorder[0]);
        res->left = nullptr;
        res->right = nullptr;
        return res;
    }
    Tree* res = new Tree(preorder[i]);
    int j = 0;
    vector<int> left;
    vector<int> right;
    while (inorder[j] != preorder[i] && j < inorder.size()) {
        left.push_back(inorder[j++]);
    }
    j++;
    while (j < inorder.size()) {
        right.push_back(inorder[j++]);
    }
    i++;
    res->left = help(preorder, left);
    i++;
    res->right = help(preorder, right);
    return res;
}
Tree* solve(vector<int>& preorder, vector<int>& inorder) {
    i = 0;
    return help(preorder, inorder);
}