#include <string>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
};

string res;
void help(TreeNode* root, bool isRoot) {
    if (!root) return;
    if (!isRoot) {
        res += '(';
        res += to_string(root->val);
        if (!root->right && !root->left) {
            res += ')';
            return;
        }   
        if (!root->right) help(root->left, false);
        else if (!root->left) {
            res += '(';
            res += ')';
            help(root->right, false);
        }
        else {
            help(root->left, false);
            help(root->right, false);
        }
        res += ')';
    }
    else {
        res += to_string(root->val);
        if (!root->right && !root->left) {
            return;
        }
        if (!root->right) help(root->left, false);
        else if (!root->left) {
            res += '(';
            res += ')';
            help(root->right, false);
        }
        else {
            help(root->left, false);
            help(root->right, false);       
        }
    }
}
string tree2str(TreeNode* root) {
    res = "";
    help(root, true);
    return res;
}

string tree2strFinal(TreeNode* root) {
    if (!root) return "";
    if (!root->right && !root->left) return to_string(root->val);
    if (!root->right) return to_string(root->val) + "(" + tree2strFinal(root->left) + ")";
    return to_string(root->val) + "(" + tree2strFinal(root->left) + ")" + "(" + tree2strFinal(root->right) + ")";
}