#include "stdc++.h"
using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n)
{
	/*int count = 0;
	vector<bool> isAvailable;
	if (flowerbed.size() == 1)
	{
		if (flowerbed[0] == 1)
		{
			count = 0;
			if (count < n)
			{
				return false;
			}
			return true;
		} 
		else 
		{
			count = 1;
			if (count < n)
			{
				return false;
			}
			return true;
		}
	}
	if (flowerbed[0] == 0 && flowerbed[1] == 0)
	{
		isAvailable.push_back(true);
	}
	else 
	{
		isAvailable.push_back(false);
	}
	for (int i = 1; i < flowerbed.size() - 1; ++i)
	{
		if (flowerbed[i] == 1)
		{
			isAvailable.push_back(false);
		}
		else 
		{
			if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0 && flowerbed[i] == 0)
			{
				isAvailable.push_back(true);
			}
			else 
			{
				isAvailable.push_back(false);
			}
		}
	}
	if (flowerbed[flowerbed.size() - 2] == 0 && flowerbed[flowerbed.size() - 1] == 0)
	{
		isAvailable.push_back(true);
	}
	else 
	{
		isAvailable.push_back(false);
	}
	for (int i = 0; i < isAvailable.size() - 1; ++i)
	{
		if (isAvailable[i] == true && isAvailable[i + 1] == true)
		{
			isAvailable[i + 1] = false;
		}
	}
	for (bool a : isAvailable)
	{
		if (a == true)
		{
			count++;
		}
	}
	if (count >= n)
	{
		return true;
	}
	return false;*/
	int size = flowerbed.size();
	int prev_one_index = -2;
	int count = 0;
	for (int i = 0; i < size; ++i)
	{
		if (flowerbed[i] == 1)
		{
			prev_one_index = i;
			continue;
		}
		if (prev_one_index != i - 1 && (i == size - 1 || flowerbed[i + 1] == 0))
		{
			count ++;
			prev_one_index = i;
		}
	}
	if (count >= n)
	{
		return true;
	}
	return false;
}


int main()
{
	vector<int> flowerbed;
	flowerbed.push_back(0);
	/*flowerbed.push_back(0);
	flowerbed.push_back(0);
	flowerbed.push_back(0);
	flowerbed.push_back(0);
	flowerbed.push_back(1);*/
	canPlaceFlowers(flowerbed, 1);
	return 0;
}
