#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
	vector<int> v1;
	vector<int> v2;
	vector<int> res;
	string s1;
	string s2;
	while(cin >> s1)
	{
	cin >> s2;
	v1.resize(0);
	v2.resize(0);
	res.resize(0);
	for (int i = 0; i < s1.length(); ++i)
	{
		v1.push_back(s1[s1.length()-i-1]-'0');
	}
	for (int i = 0; i < s2.length(); ++i)
	{
		v2.push_back(s2[s2.length()-i-1]-'0');
	}
	for (int i = 0; i < v2.size(); ++i)
	{
		for (int j = 0; j < v1.size(); ++j)
		{
			if (res.size()<i+j+1) res.push_back(0);
			res.at(i+j)+=v1.at(j)*v2.at(i);
		}
	}
	int carry=0;
#ifdef DEBUG
	for(int i=0;i<res.size();i++) cout << res.at(i) << endl;
#endif
	for (int i = 0; i < res.size(); ++i)
	{
		res.at(i)+=carry;
		carry = res.at(i)/10;
		res.at(i) %= 10;
		if (carry && i == res.size()-1) res.push_back(0);
	}
#ifndef DEBUG 
	if (res.at(res.size()-1)==0)
	{
		printf("0");
	}
	else
	{
		for(int i=res.size()-1;i>=0;i--)
		{
			printf("%d", res.at(i));   
		}
	}
	printf("\n");  
#endif  
	}                
	return 0;
}
