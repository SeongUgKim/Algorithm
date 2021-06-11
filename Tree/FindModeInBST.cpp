#include <unordered_map>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
void help(TreeNode* root, unordered_map<int, int>& mp)
{
    if (root == nullptr)
    {
        return;
    }
    help(root->left, mp);
    mp[root->val]++;
    help(root->right, mp);
}

vector<int> findMode(TreeNode* root) {
    unordered_map<int, int> mp;
    help(root, mp);
    int maxFreq = INT_MIN;
    vector<int> vec;
    for (auto m : mp)
    {
        maxFreq = max(m.second, maxFreq);
    }
    for (auto m : mp)
    {
        if (m.second == maxFreq)
        {
            vec.push_back(m.first);
        }
    }
    return vec;
}