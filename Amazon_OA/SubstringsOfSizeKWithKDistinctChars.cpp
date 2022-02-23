#include <string>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;


vector<string> solve(string& s, int k) {
	int n = s.size();
	vector<string> ans;
	if (n < k) {
		return ans;
	}
	unordered_set<string> string_set;
	unordered_map<char, int> mp;
	for (int i = 0; i < n; ++i) {
		string sub = s.substr(i, k);
		string_set.insert(sub);
	}
	for (auto str : string_set) {
		int max_number = 1;
		if (str.size() != k) continue;
		for (int i = 0; i < str.size(); ++i) {
			auto temp = str[i];
			mp[temp]++;
			max_number = max(max_number, mp[str[i]]);
			if (max_number > 1) break;	
		}
		ans.push_back(str);
	}
	return ans;
}

int main(void) {
	string s = "abcabc";
	int k = 3;
	vector<string> res = solve(s, k);
	for (auto str : res) {
		cout << str << endl;
	}
}
