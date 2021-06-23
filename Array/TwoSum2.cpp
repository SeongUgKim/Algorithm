#include "stdc++.h"
using namespace std;

vector<int> solve(vector<int>& numbers, int target)
{
    // HashTable solution
    /*
    unordered_map<int, int> mp;
    int key = INT_MIN;
    for (int i = 0; i < numbers; ++i)
    {
        key = target - numbers[i];
        if (mp.count(key))
        {
            break;
        }
        mp[numbers[i]] = i + 1;
    }
    vector<int> a;
    a.push_back(mp[key]);
    a.push_back(i + 1);
    return a;
    */
   // Two Point
    int i = 0;
    int j = numbers.size() - 1;
    vector<int> a;
    while (i < j)
    {
        int sum = numbers[i] + numbers[j];
        if (sum == target)
        {
            a.push_back(i + 1);
            a.push_back(j + 1);
            break;
        }
        if (sum > target)
        {
            j--;
        }
        else 
        {
            i++;
        }
    }
    return a;
}