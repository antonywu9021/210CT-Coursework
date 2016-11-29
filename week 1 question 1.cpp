#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <iostream>
using namespace std;
void shuffles(int* arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		srand(time(NULL)) ;
		int r = rand() % n;
		int tmp = arr[r];
		arr[r] = arr[i];
		arr[i] = tmp;
	}
}
int main()
{
	int arr[] = {5, 3, 8, 6, 1, 9, 2, 7};
	cout<<"Before shuffles: ";
	for (int i = 0; i < 8; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	shuffles(arr, 8);
	cout<<"After shuffles: ";
	for (int i = 0; i < 8; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}



