#include <string>
using namespace std;
class Solution {
public:
    int countPoints(string rings) {
        int storage[10][3] = {0, };
        int n = rings.size();
        int i = 0;
        int j = i + 1;
        while (j < n) {
            int index = rings[j] - '0';
            char character = rings[i];
            if (character == 'R') storage[index][0] = 1;
            if (character == 'G') storage[index][1] = 1;
            if (character == 'B') storage[index][2] = 1;
            i += 2;
            j = i + 1;
        }
        int ans = 0;
        for (int i = 0; i < 10; ++i) {
            int count = 0;
            for (int j = 0; j < 3; ++j) {
                if (storage[i][j] == 1) count++;
            }
            if (count == 3) ans++;
        }
        return ans;
    }
};
