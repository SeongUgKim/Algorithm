#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    // input TreeNode 
    // output 2d array
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<int> storage;
            for (int i = 0; i < sz; ++i) {
                auto curr = q.front();
                q.pop();
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
                storage.push_back(curr->val);
            }
            ans.push_back(storage);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
