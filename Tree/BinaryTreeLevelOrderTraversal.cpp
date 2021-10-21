#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
}
vector<vector<int>> leveOrder(TreeNode* root) {
	vector<vector<int>> v;
	if (!root) returnv;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		int len = q.size();
		vector<int> row;
		for (int i = 0; i < len; ++i) {
			auto* cur = q.front();
			q.pop();
			row.push_back(cur->val);
			if (cur->left) q.push(cur->left);
			if (cur->right) q.push(cur->right);
		}
		v.push_back(row);
	}
	return v;
}

