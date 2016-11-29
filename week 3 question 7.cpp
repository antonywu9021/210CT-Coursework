#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
bool prime(int n, int k)
{
	if (k == n)
	{
		return true;
	}
	if (n % k == 0)
	{
		return false;
	}
	return prime(n, k+1);
}
bool isPrime(int n)
{
	return prime(n, 2);
}
int main()
{
	if (isPrime(100))
	{
		cout<<"100 is prime."<<endl;
	}
	else
	{
		cout<<"100 is not prime."<<endl;
	}
	if (isPrime(103))
	{
		cout<<"103 is prime."<<endl;
	}
	else
	{
		cout<<"103 is not prime."<<endl;
	}
	return 0;
}

