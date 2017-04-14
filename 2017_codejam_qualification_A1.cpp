#include <string>
#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int C,a=1;
	string test;
	int len;
	cin >> C;
	while(C--)
	{
		int times=0,cnt=0;
		cin >> test >> len;
		for(int i=0; i<test.length()-len+1; ++i)
		{
			if(test[i]=='-')
			{
				for(int j=0; j<len; ++j)
				{
					test[i+j]=(test[i+j]=='+')?'-':'+';
				}
				times++;
			}
		}
		for(int i=0; i<test.length(); ++i)
		{
			if(test[i]=='-'){cnt=1;break;}
		}
		if(cnt) printf("Case #%d: IMPOSSIBLE\n",a);
		else printf("Case #%d: %d\n",a,times);
		a++;
	}
	return 0;
}
