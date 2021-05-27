int solve(string s) {
    int maxSum = INT_MIN;
    int right = 0;
    int left = 0;
    for (char c : s)
    {
        right += c == '1';
    }
    for (int i = 0; i < s.size() - 1;  ++i)
    {
        left += s[i] == '0';
        right -= s[i] == '1';
        maxSum = max(maxSum, left + right);
    }
    return maxSum;
}

// line sweeping algorithm
int solve(string s) {
    int res = INT_MIN;
    int left_ones = 0;
    int i = 0;
    for (; i < s.size() - 1;  ++i)
    {
        left_ones += s[i] == '1';
        res = max(res, i + 1 - left_ones - left_ones);
    }
    left_ones += s[i] == '1';
    return res + left_ones;
}