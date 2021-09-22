#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
};
void inorder(TreeNode* root, vector<int>& vec) {
    if (!root) return;
    inorder(root->left, vec);
    vec.push_back(root->val);
    inorder(root->right, vec);
}
bool findTarget(TreeNode* root, int k) {
    vector<int> vec;
    unordered_map<int, int> mp;
    inorder(root, vec);
    for (int i = 0; i < vec.size(); ++i) {
        if (mp[k - vec[i]] != 0) return true;
        mp[vec[i]]++;
    }
    return false;
}

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        if (s.count(k - root->val)) return true;
        s.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
private:
    unordered_set<int> s;
};