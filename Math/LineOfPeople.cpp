int solve(int n, int a, int b) {
    int sum = a + b;
    if (n > sum) return b + 1;
    return n - a;
}