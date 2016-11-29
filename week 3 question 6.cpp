#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
void reverse(char* s, int beg, int end)
{
	end--;
	while (beg < end)
	{
		char tmp = s[beg];
		s[beg] = s[end];
		s[end] = tmp;
		beg++;
		end--;
	}
}
void reverseWord(char* s, int len)
{
	reverse(s, 0, len);
	int beg = 0;
	int end;
	while (beg<len)
	{
		while (beg<len && s[beg]==' ')
		{
			beg++;
		}
		if (beg>=len)
		{
			break;
		}
		end=beg+1;
		while (end<len && s[end]!=' ')
		{
			end++;
		}
		reverse(s, beg, end);
		beg=end+1;
	}
}
int main()
{
	char s[] = "This is awesome";
	reverseWord(s, 15);
	cout<<"Reverse the words in \"This is awesome is\" is "<<s<<endl;
	return 0;
}

