int solve(string s, int k) {
    unordered_set<char> st;
    int div = k / 2;
    if (k % 2 != 0) div++;
    for (char c : s) {
        st.insert(c);
    }
    int len = st.size();
    return pow(len, div);
}
