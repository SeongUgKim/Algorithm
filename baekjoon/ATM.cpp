#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int solve(vector<int>& p)
{
        sort(p.begin(), p.end());
        int n = p.size();
        int sum = 0;
        int prev = 0;
        for (int i = 0; i < n; ++i) {
                prev = prev + p[i];
                sum += prev;                    
        }
        return sum;
}       
        
int main()
{
        int n;
        vector<int> p;
        cin >> n;
        int temp;
        for (int i = 0; i < n; ++i) { 
                cin >> temp;
                p.push_back(temp);
        }
        int result = solve(p);
        cout << result << endl;
}
