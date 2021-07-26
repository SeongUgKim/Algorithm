class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <vector>
using namespace std;
void inorder(TreeNode* root, vector<int>& vec) {
    if (!root) return;
    inorder(root->left, vec);
    vec.push_back(root->val);
    inorder(root->right, vec);
}
int getMinimumDifference(TreeNode* root) {
    vector<int> vec;
    vector<int> res;
    inorder(root, vec);
    int n = vec.size();
    int min_val = INT_MAX;
    for (int i = 1; i< n; ++i) {
        min_val = min(vec[i] - vec[i - 1], min_val);
    }
    return min_val;
}