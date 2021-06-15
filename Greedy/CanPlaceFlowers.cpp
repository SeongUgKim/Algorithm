#include <vector>
using namespace std;
bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    if (n == 0)
    {
        return true;
    }
    int m = flowerbed.size();
    if (m == 1)
    {
        return flowerbed[0] == 1 ? false : true;
    }
    if (flowerbed[0] == 0 && flowerbed[1] == 0)
    {
        flowerbed[0] = 1;
        n--;
        if (n == 0)
        {
            return true;
        }
    }
    if (flowerbed[m - 1] == 0 && flowerbed[m - 2] == 0)
    {
        flowerbed[m - 1] = 1;
        n--;
        if (n == 0)
        {
            return true;
        }
    }
    for (int i = 1; i < m - 1; ++i)
    {
        if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0)
        {
            flowerbed[i] = 1;
            n--;
            if (n == 0)
            {
                return true;
            }
        }
    }
    return n == 0;
}