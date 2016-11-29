#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
bool bSearch(int* arr, int len, int small, int large)
{
	if (len < 1 || small > large)
	{
		return false;
	}
	int left = 0, right = len - 1;
	while (left <= right)
	{
		int mid = (left + right)/2;
		if (arr[mid] < small)
		{
			left = mid + 1;
		}
		else if (arr[mid] > large)
		{
			right = mid - 1;
		}
		else
		{
			return true;
		}
	}
	return false;
}
int main()
{
	int arr[] = {2, 3, 5, 7, 9, 13};
	if (bSearch(arr, 6, 10, 14))
	{
		cout<<"True"<<endl;
	}
	else
	{
		cout<<"False"<<endl;
	}
	return 0;
}

