#include <utility>
using namespace std;

class Tree 
{
public:
	int val;
	Tree* left;
	Tree* right;
};

pair<int, int> help(Tree* root)
{
    if (!root->left && !root->right) return {root->val, 1};
    pair<int, int> left;
    pair<int, int> right;
    if (!root->left) {
        right = help(root->right);
        return {root->val + right.first, right.second + 1};
    }
    if (!root->right) {
        left = help(root->left);
        return {root->val + left.first, left.second + 1};
    }
    left = help(root->left);
    right = help(root->right);
    if (left.second == right.second) return left.first > right.first ? make_pair(root->val + left.first, left.second + 1) : make_pair(root->val + right.first, right.second + 1);
    return left.second > right.second ? make_pair(root->val + left.first, left.second + 1) : make_pair(root->val + right.first, right.second + 1);
}
int solve(Tree* root)
{
    pair<int, int> res = help(root);
    return res.first;
    
}
