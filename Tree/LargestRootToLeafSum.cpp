#include <vector>
#include <climits>
using namespace std;
class Tree {
public:
    int val;
    Tree *left;
    Tree *right;
 };
 void help(Tree* root, vector<int>& vec, int sum) {
    if (!root) return;
    if (root->left == nullptr && root->right == nullptr) {
        vec.push_back(sum + root->val);
        return;
    }
    help(root->right, vec, sum + root->val);
    help(root->left, vec, sum + root->val);
}
int solve(Tree* root) {
    vector<int> vec;
    help(root, vec, 0);
    int max_val = INT_MIN;
    for (int a : vec) {
        max_val = max(a, max_val);
    }
    if (max_val < 0) return 0; 
    return max_val;
}