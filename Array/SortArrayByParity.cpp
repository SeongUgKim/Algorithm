#include "stdc++.h"
using namespace std;

vector<int> solve(vector<int> A)
{
    /*vector<int> ret(A.size(), -1);
    vector<int> temp(A.size(), -1);
    for (int i = 0; i < A.size(); ++i)
    {
        if (i % 2 == A[i] % 2)
        {
            ret[i] = A[i];
            continue;
        }
        temp[i] = A[i];
    }
    for (int i = 0; i < temp.size(); ++i)
    {
        if (temp[i] == -1)
        {
            continue;
        }
        if (temp[i] % 2 == 0)
        {
            for (int j = 0; j < ret.size(); j += 2)
            {
                if (ret[j] == -1)
                {
                    ret[j] = temp[i];
                    break;
                }
            }
        }
        else 
        {
            for (int j = 1; j < ret.size(); j += 2)
            {
                if (ret[j] == -1)
                {
                    ret[j] = temp[i];
                    break;
                }
            }
        }
    }
    return ret;*/
    vector<int> ret(A.size(), -1);
    int even = 0;
    int odd = 1;
    for (int i = 0; i < A.size(); ++i)
    {
        if (A[i] % 2 == 0)
        {
            ret[even] = A[i];
            even += 2;
        }
        else 
        {
            ret[odd] = A[i];
            odd += 2;
        }
    }
    return ret;
}   
int main()
{
    vector<int> A = {7, 14, 9, 16};
    vector<int> ret = solve(A);
    for (int a : ret)
    {
        cout << a << " "; 
    }
    cout << endl;
    return 0;
}