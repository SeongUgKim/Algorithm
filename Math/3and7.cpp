bool topdown(int n) {
    if (n == 0) return true;
    if (n < 0) return false;
    if (n % 7 == 0 || n % 3 == 0) return true;
    return topdown(n - 3) || topdown(n - 7);
}
bool solve(int n) {
    return topdown(n);
}