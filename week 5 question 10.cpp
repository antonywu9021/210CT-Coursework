#include <iostream>
using namespace std;
#define MAX 100
int find(int p[],int n, int s[])
{
	int temp[MAX]={0};
	int length=0,t=0;
	for(int i=0;i<n-1;i++)
	{
		temp[0]=p[i];
		t++;
		for(int j=i+1;j<n;j++)
		{
			if(p[j]>p[j-1])
			{
				temp[t]=p[j];
				t++;
			}else
			{
				break;
			}
		}
		if(t>length)
		{
			for(int k=0;k<t;k++)
			{
				s[k]=temp[k];
			}
			length=t;
		}
		t=0;
	}
	return length;
}
int main()
{
	int a[]={1,0,8,4,5,6};
//	int a[]={1,2,3,4,5,6};
//	int a[]={1,0,8,4,5,6};
//	int a[]={1,8,2,7,3,6,4,5};
//	int a[]={1,2,3,4,8,5,7};
	int b[MAX]={0};
	int k=find(a,sizeof(a)/sizeof(a[0]),b);
	cout<<"Enter a sequence of number: "<<endl;
	for(int j=0;j<sizeof(a)/sizeof(a[0]);j++)
		cout<<a[j]<<" ";
	cout<<endl;
	cout<<"the sub-sequence of maximum length is: "<<endl;
	for(int i=0;i<k;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}


