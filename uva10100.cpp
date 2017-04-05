#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
	int a=1;
	int **lcs = new int *[500];
	int *tmp = new int[250000];
	for(int i=0; i<500; ++i)
	{
		lcs[i] = &tmp[i*500];
	}
	char delim[]=" ~!@#$%^&*()`<>?:{}_+|-=[]\\;',./\"\n";
	string s1,s2;
	vector<string> v1,v2;

	char *cs1 = new char[1006];
	char *cs2 = new char[1006];
	while(fgets(cs1,1005,stdin)!=NULL)
	{
		fgets(cs2,1005,stdin);
		v1.resize(0);
		v2.resize(0);
		for(char *p=strtok(cs1,delim);p != NULL;p=strtok(NULL,delim))
		{
			v1.push_back(string(p));
		}
		for(char *p=strtok(cs2,delim);p != NULL;p=strtok(NULL,delim))
		{
			v2.push_back(string(p));
		}
		if(v1.empty() or v2.empty())
		{
			printf("%2d. Blank!\n",a);
			a++;
			continue;
		}



		for(int i=0; i<500; ++i)
		{
			for(int j=0; j<500; ++j)
			{
				lcs[i][j]=0;
			}
		}
		for(int i=0; i<v1.size(); ++i)
		{
			for(int j=0; j<v2.size(); ++j)
			{
				if(v1[i]==v2[j]) lcs[i+1][j+1]=lcs[i][j]+1;
				else lcs[i+1][j+1]=max(lcs[i][j+1],lcs[i+1][j]);
			}
		}
		cout << setw(2) << a << ". Length of longest match: " << lcs[v1.size()][v2.size()] << endl;
		a++;
	}
	return 0;
}
