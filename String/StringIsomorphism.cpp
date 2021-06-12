using namespace std;
bool solve(string s, string t) {
    if (s == t)
    {
        return true;
    }
    int m = s.size();
    int n = t.size();
    if (m != n)
    {
        return false;
    }
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < n; ++i)
    {
        count1 = 0;
        count2 = 0;
        for (int j = 0; j < n; ++j)
        {
            if (s[i] == s[j])
            {
                count1++;
            }
            if (t[i] == t[j])
            {
                count2++;
            }
        }
        if (count1 != count2)
        {
            return false;
        }
    }
    return true;
}