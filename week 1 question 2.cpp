#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int numberOf5(int n)
{
	int ret = 0;
	while(n % 5 == 0)
	{
		n /= 5;
		ret ++;
	}
	return ret;
}
int numberOf0(int n)
{
	int ret = 0;
	for (int i = 5; i <= n; ++i)
	{
				ret += numberOf5(i);
	}
	return ret;
}
int main()
{
	cout<<"The number of trailing 0s in a factorial number 100 is "<<numberOf0(100)<<endl;
	return 0;
}

