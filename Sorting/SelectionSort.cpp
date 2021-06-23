#include "stdc++.h"
using namespace std;

void selctionSort(vector<int>& arr)
{
    for (int i = 0; i < arr.size() - 1; ++i)
    {
        int min = i;
        for (int j = i + 1; j < arr.size(); ++j)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    vector<int> arr = {45, 64, 22, 47, 11, 93};
    for (int a : arr)
    {
        cout << a << " ";
    }
    cout << endl;
    selctionSort(arr);
    for (int a : arr)
    {
        cout << a << " ";
    }
    cout << endl;
}
