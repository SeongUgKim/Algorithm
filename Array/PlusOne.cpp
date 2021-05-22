#include <vector>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int carry = 0;
    int n = digits.size();
    vector<int> res;
    int digit = digits[n - 1];
    digit++;
    if (digit == 10) {
        carry = 1;
        digit = 0;
    }
    res.push_back(digit);
    for (int i = n - 2; i >= 0; --i)
    {
        int digit = digits[i];
        if (carry == 1)
        {
            digit++;
            carry = 0;
        }
        if (digit == 10)
        {
            carry = 1;
            digit = 0;
        }
        res.push_back(digit);
    }
    if (carry == 1)
    {
        res.push_back(1);
    }
    reverse(res.begin(), res.end());
    return res;
}

vector<int> solve(vector<int> digits)
{
    int n = digits.size();
    for (int i = n - 1; i >= 0; --i)
    {
        if (digits[i] != 9) 
        {
            digits[i]++;
            return digits;
        }
        digits[i] = 0;
    }
    digits.push_back(0);
    digits[0] = 1;
    return digits;
}