#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        vector<int> hash(26, 0);
        vector<int> phash(26, 0);
        int np = p.size();
        int ns = s.size();
        if (np > ns) return res;
        int left = 0;
        int right = 0;
        while (right < np) {
            hash[s[right] - 'a']++;
            phash[p[right] - 'a']++;
            right++;
        }
        right -= 1;
        while (right < ns) {
            if (hash == phash) {
                res.push_back(left);
            }
            right++;
            if (right != ns) {
                hash[s[right] - 'a']++;
            }
            hash[s[left] - 'a']--;
            left++;
        }
        return res;
    }
};
