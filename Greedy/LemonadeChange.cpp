#include <vector>
using namespace std;
bool lemonadeChange(vector<int>& bills) {
    int five = 0;
    int ten = 0;
    for (int i = 0; i < bills.size(); ++i)
    {
        if (bills[i] == 5)
        {
            five++;
            continue;
        }
        if (bills[i] == 10)
        {
            if (five == 0)
            {
                return false;
            }
            five--;
            ten++;
            continue;
        }
        if (bills[i] == 20)
        {
            if (five == 0)
            {
                return false;
            }
            if (ten == 0)
            {
                if (five < 3)
                {
                    return false;
                }
                five -= 3;
            }
            else
            {
                five--;
                ten--;
            }
        }
    }
    return true;
}