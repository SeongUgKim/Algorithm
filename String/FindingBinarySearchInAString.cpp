#include <string>
#include <vector>
using namespace std;

bool solve(string s) {
    int n = s.size();
    vector<int> diffs;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (s[i] == 'b' && s[j] == 'i') diffs.push_back(j - i);
        }
    }
    string bs = "binarysearch";
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'b') {
            for (int j = 0; j < diffs.size(); ++j) {
                int diff = diffs[j];
                int val = 0;
                bool flag = false;
                int k = i;
                for (; k < n; k += diff) {
                    if (bs[val++] != s[k]) {
                        flag = false;
                        break;
                    }
                    if (val == bs.size()) {
                        flag = true;
                        break;
                    }
                }
                if (flag) return true;
            }
        }
    }
    return false;
}