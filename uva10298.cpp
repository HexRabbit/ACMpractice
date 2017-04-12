#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;
int bt[1000000]={0};
int main()
{
	int a=0;
	string str;
	while(1)
	{
		memset(bt,0,1000000);
		int p,cc=0;
		cin >> str;
		if(str==".") break;
		int n=str.length();
		for(int i=0; i<n; ++i)
		{
			for(int j=0; i+j<n; ++j)
			{
				if(str[j+i]==str[j]) bt[i]++;
				else break;
			}
		}
		for(p=1; p<=n/2; ++p)
		{
			int t=1;
			if(bt[p]+p==n){
				while(n-p*t>0 && bt[p*t]==n-p*t) t++;
				if(n-p*t==0) {cc=1;break;}
				//c=1;break;
			}
		}
		if(cc) printf("%d\n",n/p);
		else printf("1\n");
	}
}
