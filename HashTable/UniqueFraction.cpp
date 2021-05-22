#include <vector>
#include <unordered_set>
#include <algorithm>
vector<vector<int>> solve(vector<vector<int>>& fractions) {
    unordered_set<double> check;
    vector<int> indice;
    vector<vector<int>> res;
    int dividen;
    int divisor;
    int q;
    int r;
    for (int i = 0; i < fractions.size(); ++i)
    {
        dividen = fractions[i][0];
        divisor = fractions[i][1];
        while (divisor != 0)
        {
            q = dividen / divisor;
            r = dividen % divisor;
            dividen = divisor;
            divisor = r;
        }
        dividen = dividen < 0 ? dividen * - 1 : dividen;
        fractions[i][0] /= dividen;
        fractions[i][1] /= dividen;
    }
    for (int i = 0; i < fractions.size(); ++i)
    {
        double value = (fractions[i][0] + 0.0) / (fractions[i][1] + 0.0);
        if (check.count(value))
        {
            continue;
        }
        check.insert(value);
        indice.push_back(i);
    }
    int n = indice.size();
    res.resize(n, vector<int>(2, 0));
    int k = 0;
    for (int i = 0; i < n; ++i)
    {
        int row = indice[i];
        res[i][0] = fractions[row][0];
        res[i][1] = fractions[row][1];
    }
    sort(res.begin(), res.end(), [](auto a, auto b) { return a[0] * b[1] < a[1] * b[0]; });
    return res;
}
