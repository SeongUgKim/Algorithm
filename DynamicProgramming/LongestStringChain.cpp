#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;
int dfs(unordered_set<string>& words, unordered_map<string, int>& memo, string currentWord) {
		if (memo.find(currentWord) != memo.end()) return memo[currentWord];
		int maxLength = 1;
		for (int i = 0; i < currentWord.size(); ++i) {
		    string newWord = currentWord.substr(0, i) + currentWord.substr(i + 1);
		    if (words.find(newWord) != words.end()) {
		        int currentLength = 1 + dfs(words, memo, newWord);
		        maxLength = max(maxLength, currentLength);
		    }
		}
		memo[currentWord] = maxLength;
		return maxLength;
		}
		
		int topdown(vector<string>& words) {
		unordered_map<string, int> memo;
		unordered_set<string> wordsPresent;
		for (const string& word : words) {
		    wordsPresent.insert(word);
		}
		int ans = 0;
		for (const string& word : words) {
		    ans = max(ans, dfs(wordsPresent, memo, word));
		}
		return ans;
}

int bottomup(vector<string>& words) {
		unordered_map<string, int> dp;
		sort(words.begin(), words.end(), [](const string& word1, const string& word2){
		    return word1.size() < word2.size();
		});
		
		int longestWordSequenceLength = 1;
		for (const string& word : words) {
		    int presentLength = 1;
		    for (int i = 0; i < word.length(); ++i) {
		        string predecessor = word.substr(0, i) + word.substr(i + 1, word.size() + 1);
		        if (dp.find(predecessor) != dp.end()) {
		            int previousLength = dp[predecessor];
		            presentLength = max(previousLength + 1, presentLength);
		        }
		    }
		    dp[word] = presentLength;
		    longestWordSequenceLength = max(longestWordSequenceLength, presentLength);
		}
		return longestWordSequenceLength;
}
