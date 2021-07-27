#include <vector>
#include <numeric>
using namespace std;
bool canThreePartsEqualSum(vector<int>& arr) {
    int n = arr.size();
    int sum = 0;
    sum = accumulate(arr.begin(), arr.end(), sum);
    if (sum % 3 != 0) return false;
    sum /= 3;
    int count = 0;
    int add = 0;
    for (int a : arr) {
        add += a;
        if (add == sum) {
            count++;
            add = 0;
        }
    }
    return count >= 3;
}