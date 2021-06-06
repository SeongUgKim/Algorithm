#include <utility>
using namespace std;
class Tree{
public:
    int val;
    Tree* left;
    Tree* right;
};
pair<int,int> help(Tree* root)
{
    int maxVal = INT_MIN;
    if (root == nullptr)
    {
        return make_pair(0, maxVal);
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        maxVal = max(maxVal, root->val);
        return make_pair(1, maxVal);
    }
    pair<int, int> p1 = help(root->left);
    pair<int, int> p2 = help(root->right);
    int maximum = max(p1.second, p2.second);
    int count = p1.first + p2.first;
    if (root->val >= maximum)
    {
        count++;
        maximum = root->val;
    }
    return make_pair(count, maximum);
}

int solve(Tree* root) {
    pair<int, int> p = help(root);
    return p.first;
}