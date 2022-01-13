#include <queue>
using namespace std;

class Tree {
public:
	int val;
	Tree* left;
	Tree* right;
}

int solve(Tree* root) {
    queue<Tree*> q;
    if (root) q.push(root);
    int res = 0;
    while (!q.empty()) {
        int n = q.size();
        res = 0;
        for (int i = 0; i < n; ++i) {
            auto p = q.front();
            res += p->val;
            if (p->left) q.push(p->left);
            if (p->right) q.push(p->right);
            q.pop()
        }
    }
    return res;
}
