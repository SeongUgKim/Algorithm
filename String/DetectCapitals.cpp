#include <string>
using namespace std;
class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() == 1) return true;
        bool first = (word[0] >= 'a' && word[0] <= 'z') ? false : true;
        bool second = (word[1] >= 'a' && word[1] <= 'z') ? false : true;
        if (!first && second) return false;
        int n = word.size();
        for (int i = 2; i < n; ++i) {
            if (first && second)  {
                if (word[i] < 'A' || word[i] > 'Z') return false;
            } else {
                if (word[i] < 'a' || word[i] > 'z') return false;   
            }
        }
        return true;
    }
};
