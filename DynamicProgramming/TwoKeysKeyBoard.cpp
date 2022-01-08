#include <cstring>
#include <climits>
using namespace std;
int minSteps(int n) {
    int cache[1001];
    memset(cache, 0, sizeof(cache));
    cache[0] = 0;
    cache[1] = 0;
    cache[2] = 2;
    int min_value = INT_MAX;
    for (int i = 3; i <= n; ++i) {
        for (int j = 1; j <= i / 2; ++j) {
            if (i % j != 0) continue;
            int remain = i - j;
            remain /= j;
            remain++;
            min_value = min(min_value, remain + cache[j]);
        }
        cache[i] = min_value;
        min_value = INT_MAX;
    }
    return cache[n];
}
