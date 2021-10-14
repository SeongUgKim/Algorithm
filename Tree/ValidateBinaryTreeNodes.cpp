#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	  void dfs(unordered_set<int>& visited, int& curr_node, vector<int>& leftChild, vector<int>& rightChild) {
	  	if (visited.count(curr_node) || curr_node == -1) return;
		visited.insert(curr_node);
		dfs(visited, leftChild[curr_node], leftChild, rightChild);
		dfs(visited, rightChild[curr_node], leftChild, rightChild);
	  }

	  bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
	  	unordered_set<int> find_root;
	       	for (int i = 0; i < n; ++i) 
			find_root.insert(i);
		for(int i = 0; i < n; ++i) {
			if (leftChild[i] != -1) {
				if (!find_root.count(leftChild[i])) return false;
				find_root.erase(leftChild[i];
			}
			if (rightChild[i] != -1) {
				if (!find_root.count(rightChild[i])) return false;
				find_root.erase(rightChild[i];
			}
		}

		if (find_root.size != 1) return false;
		int root = *find_root.begin();
		unordered_set<int> visited;
		dfs(visited, root, leftChild, rightChild);
		return visited.size() == n;
	  }
};
