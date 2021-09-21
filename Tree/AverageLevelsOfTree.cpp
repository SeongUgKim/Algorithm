#include <vector>
#include <queue>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<double> bfs(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<double> res;
        while (!q.empty()) {
            double sum = 0.0;
            vector<TreeNode*> v;
            while (!q.empty()) {
                if (q.front() != nullptr) {
                    sum += static_cast<double>(q.front()->val);
                    v.push_back(q.front());
                }
                q.pop();
            }
            for (int i = 0; i < v.size(); ++i) {
                q.push(v[i]->left);
                q.push(v[i]->right);
            }
            if (v.size() == 0) break;
            double avg = sum / v.size();
            res.push_back(avg);
        }
        return res;
    }