#include "stdc++.h"
using namespace std;

int BinarySearch(int arr[], int left, int right, int x)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] < x)
        {
            left = mid + 1;
        }
        else 
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    enum { MAX = 10};
    int arr[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int left = 0;
    int right = MAX - 1;
    int num = 10;
    int index = BinarySearch(arr, left, right, num);
    cout << index << endl;
    return 0;
}