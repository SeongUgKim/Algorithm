#include <vector>
using namespace std;
class Tree {
public:
    int val;
    Tree* left;
    Tree* right;
};

void helper(int& leaf, int& internalNode, Tree* root)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        leaf++;
    }
    else
    {
        internalNode++;
    }
    helper(leaf, internalNode, root->left);
    helper(leaf, internalNode, root->right);
}
vector<int> solve(Tree* root) {
    int leaf = 0;
    int internalNode = 0;
    helper(leaf, internalNode, root);
    vector<int> vec;
    vec.push_back(leaf);
    vec.push_back(internalNode);
    return vec;
}