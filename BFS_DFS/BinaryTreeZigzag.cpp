#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int toggle = 0;
        vector<int> vec;
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            if (temp.second == 0) {
                if(toggle == 1) {
                    reverse(vec.begin(), vec.end());
                    ans.push_back(vec);
                    vec = vector<int>();
                    toggle = 0;
                }
                if (!temp.first) continue;
                q.push({temp.first->left, 1});
                q.push({temp.first->right, 1});
                vec.push_back(temp.first->val);
            } else {
                if (toggle == 0) {
                    ans.push_back(vec);
                    vec = vector<int>();
                    toggle = 1;
                }
                if (!temp.first) continue;
                q.push({temp.first->left, 0});
                q.push({temp.first->right, 0});
                vec.push_back(temp.first->val);
            }
        }
        return ans;
    }
		vector<vector<int>> zigzagLevelOrderSecond(TreeNode* root) {
        vector<vector<int>> ans;
        ans.clear();
        if (!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        while (!q.empty()) {
            int n = q.size();
            vector<int> level(n);
            for (int i = 0; i < n; ++i) {
                auto node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                level[i] = node->val;
            }
            if (flag) reverse(level.begin(), level.end());
            ans.push_back(level);
            flag = !flag;
        }
        return ans;
    }
};
