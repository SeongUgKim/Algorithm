#include <vector>
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
};

void helper(vector<int>& res, TreeNode* root)
{
    if (root == nullptr)
    {
        return;
    }
    helper(res, root->left);
    res.push_back(root->val);
    helper(res, root->right);
}

vector<int> inorderTraversalRecursive(TreeNode* root) {
    vector<int> res;
    helper(res, root);
    return res;
}


vector<int> inorderTraversalIterative(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> st;
    while (!st.empty() || root != nullptr)
    {
        while (root != nullptr)
        {
            st.push(root);
            root = root->left;
        }
        root = st.top();
        st.pop();
        res.push_back(root->val);
        root = root->right;
    }
    return res;
}



