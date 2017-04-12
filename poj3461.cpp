#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	int C;
	cin >> C;
	while(C--)
	{
		string str;
		string test;
		cin >> str >> test;
		int cnt=0;
		int rec[10005];
		memset(rec,-1,sizeof*rec);
		int pt=-1;
		for(int i=1; i<str.length(); ++i)
		{
			while(~pt && str[i]!=str[pt+1]) pt=rec[pt];
			if(str[i]==str[pt+1]) pt++;
			rec[i]=pt;
		}
		for(int i=0,j=0; j<test.length();)
		{
			if(test[j]==str[i])
			{
				i++;j++;
			}
			else
			{
				if(rec[i]!=-1) i=rec[i-1]+1;
				else {j=j-i+1;i=0;}
			}
			if(i==str.length())
			{
				cnt++;
				i=rec[i-1]+1;
			}
		}
		printf("%d\n",cnt);
	}
}
