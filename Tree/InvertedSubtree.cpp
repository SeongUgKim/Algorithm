#include <vector>
using namespace std;

class Tree {
public:
    int val;
    Tree* left;
    Tree* right;
};

vector<Tree*> roots;
void findRoot(Tree* target, int value) {
    if (!target) return;
    if (target->val == value) {
        roots.push_back(target);
    }
    findRoot(target->left, value);
    findRoot(target->right, value);
}
bool checkInverse(Tree* source, Tree* target) {
    if (source == nullptr && target == nullptr) return true;
    if (source == nullptr || target == nullptr) return false;
    if (source->val != target->val) return false;
    return (checkInverse(source->left, target->right) && checkInverse(source->right, target->left)) || (checkInverse(source->right, target->right) && checkInverse(source->left, target->left));
}
bool solve(Tree* source, Tree* target) {
    roots = {};
    int value = source->val;
    findRoot(target, value);
    bool res = false;
    for (Tree* root : roots) {
        bool temp = checkInverse(source, root);
        res = res || temp;
    }
    return res;
}