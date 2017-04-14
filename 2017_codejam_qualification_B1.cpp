#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
string test;
int sminus(char &check);
bool isTidy();
int main(int argc, char const *argv[])
{
	int cnt,a=1;
	cin >> cnt;
	while(cnt--)
	{
		cin >> test;
		while(!isTidy())
		{
			sminus(test.back());
		}
		string::iterator it;
		if(test[0]=='0')
		{
			for(it=test.begin(); it<test.end(); ++it) if(*it!='0') break;
			printf("Case #%d: ",a);
			for(; it<test.end(); ++it)
			{
				printf("%c",*it);
			}
			cout << endl;
		}
		else
		{
			printf("Case #%d: ",a);
			cout << test << endl;
		}
		a++;
	}
	return 0;
}

bool isTidy()
{
	for (int i = 0; i < test.length()-1; ++i)
	{
		if (test[i]-'0' > test[i+1]- '0')
		{
			while(i < test.length()){i++;test[i+1]='0';}
			return false;
		}
	}
	return true;
}

int sminus(char &check)
{
	if(&check < &*test.begin()) return 0;
	if (check - '0' > 0)
	{
		--check;
		return 1;
	}
	else
	{
		if (sminus(*(&check-1)))
		{
			check = '9';
		}
	}
}
