#include <vector>
using namespace std;
class Tree {
public:
    int val;
    Tree *left;
    Tree *right;
};

void help(Tree* root, vector<int>& depth, int level) {
    if (!root) return;
    if (root->left == nullptr && root->right == nullptr) {
        depth.push_back(level);
        return;
    }
    help(root->left, depth, level + 1);
    help(root->right, depth, level + 1);
}
int solve(Tree* root) {
    vector<int> depth;
    help(root, depth, 0);
    int n = depth.size();
    sort(depth.begin(), depth.end());
    int res = depth[n - 1];
    for (int i = n - 1; i >= 0; --i) {
        if (depth[i] != res) {
            res = depth[i];
            break;
        }
    }
    return res;
}