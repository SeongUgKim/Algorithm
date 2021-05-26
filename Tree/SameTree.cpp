#include <vector>
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
};

// Preorder check
void helper(vector<TreeNode*>& vec, TreeNode* p)
{
    if (p == nullptr)
    {
        vec.push_back(nullptr);
        return;
    }
    vec.push_back(p);
    helper(vec, p->left);
    helper(vec, p->right);
}

bool isSameTree(TreeNode* p, TreeNode* q) {
    vector<TreeNode*> vec1;
    vector<TreeNode*> vec2;
    helper(vec1, p);
    helper(vec2, q);
    int m = vec1.size();
    int n = vec2.size();
    if (m != n)
    {
        return false;
    }
    for (int i = 0; i < m; ++i)
    {
        if (vec1[i] == nullptr)
        {
            if (vec2[i] != nullptr)
            {
                return false;
            }
            continue;
        }
        if (vec2[i] == nullptr)
        {
            if (vec1[i] != nullptr)
            {
                return false;
            }
            continue;
        }
        if (vec1[i]->val != vec2[i]->val)
        {
            return false;
        }
    }
    return true;
}

// Recursive
bool isSameTreeRecursive(TreeNode* p, TreeNode* q)
{
    if (p == nullptr && q == nullptr)
    {
        return true;
    }
    if (p == nullptr || q == nullptr)
    {
        return false;
    }
    if (p->val != q->val)
    {
        return false;
    }
    return isSameTreeRecursive(p->left, q->left) && isSameTreeRecursive(p->right, q,right);
}

// Iterative After Learning BFS