#include <vector>
#include <string>
using namespace std;
int sum(int n) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }
    return sum;
}
int solve(string s) {
    vector<int> v;
    int cur = 0;
    int next = 1;
    int count = 0;
    for (int i = 0; i <s.size(); ++i) {
        count = 0;
        if (s[i] == '1') {
            count = 1;
            int j = i + 1;
            for (; j < s.size(); ++j) {
                if (s[j] == '1') count++;
                else break;
            }
            v.push_back(count);
            i = j;
        }
    }
    int res = 0;
    for (int i = 0; i < v.size(); ++i) {
        res += sum(v[i]);
    }
    return res;

}