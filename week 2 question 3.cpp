#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int solve(int n)
{
	int ret = 0;
	while ((ret+1)*(ret+1)<=n)
	{
		ret++;
	}
	return ret;
}
int main()
{
	cout<<"solve(105) = "<<solve(105)<<endl;
	return 0;
}

