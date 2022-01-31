#include <vector>
using namespace std;

class Solution {
public:
    // input : binary tree
    // output : 2d array
    TreeNode* dfs(TreeNode* root, vector<int>& vec) {
        if (!root) return nullptr;
        if (!root->right && !root->left) {
            vec.push_back(root->val);
            return nullptr;
        }
        root->left = dfs(root->left, vec);
        root->right = dfs(root->right, vec);
        return root;
    }   
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        while (root) {
            vector<int> vec;
            root = dfs(root, vec);
            ans.push_back(vec);
        }
        return ans;
    }
};
