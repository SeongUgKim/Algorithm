#include "stdc++.h"
using namespace std;

int solve(int start, int end)
{
    int count = 0;
    if (end % 2 == 1)
    {
        end--;
        count++;
    }
    while (end / 2 >= start)
    {
        end /= 2;
        if (end % 2 == 1)
        {
            end--;
            count++;
        }
        count++;
    }
    count += (end - start);
    return count;
}

int main()
{
    cout << solve(2, 9) << endl;
    return 0;
}