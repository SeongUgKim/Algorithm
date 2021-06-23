#include "stdc++.h"
using namespace std;

string solve(int n)
{
    /*vector<int> v;
    int carry = 0;
    while (n > 26)
    {
        int mod = n % 26;
        if (mod == 0)
        {
            mod = 26;
            carry++;
        }
        v.push_back(mod);
        n /= 26;
        n -= carry;
        carry = 0;
    }
    v.push_back(n);
    int start = 0;
    int end = v.size() - 1;
    while (start < end)
    {
        swap(v[start], v[end]);
        start++;
        end--;
    }
    string ret = "";
    for (int a : v)
    {
        ret += a - 1 + 'A';
    }
    return ret;*/
    string ans;
	while(n){
		n-=1;
		ans=(char)(n%26+'A')+ ans;
		n/=26;
	}
	return ans;
}

int main()
{
    cout << solve(28) << endl;
    return 0;
}