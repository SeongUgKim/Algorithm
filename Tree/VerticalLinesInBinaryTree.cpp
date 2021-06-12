#include <unordered_set>
using namespace std;
class Tree{
public:
    int val;
    Tree* left;
    Tree* right;
};
void dfs(Tree* root, unordered_set<int>& st, int d)
{
    if (root == nullptr)
    {
        return;
    }
    st.insert(d);
    dfs(root->left, st, d - 1);
    dfs(root->right, st, d + 1);
}
int solve(Tree* root) {
    unordered_set<int> st;
    dfs(root, st, 0);
    return st.size();
}
