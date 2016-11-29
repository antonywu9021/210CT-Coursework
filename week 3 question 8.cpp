#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
void removeVowelRecursion(char* s, int k)
{
	if (s[k]=='\0')
	{
		return;
	}
	if (s[k]=='a' || s[k] == 'A' 
		|| s[k]=='e' || s[k] == 'E' 
		|| s[k]=='i' || s[k] == 'I' 
		|| s[k]=='o' || s[k] == 'O' 
		|| s[k]=='u' || s[k] == 'U')
	{
		int i = k;
		while(s[i] != '\0')
		{
			s[i] = s[i+1];
			i++;
		}
		removeVowelRecursion(s, k);
	}
	else
	{
		removeVowelRecursion(s, k + 1);
	}
}
void removeVowel(char* s)
{
	removeVowelRecursion(s, 0);
}
int main()
{
	char s[] = "beautiful";
	cout<<s<<"->";
	removeVowel(s);
	cout<<s<<endl;
	return 0;
}

