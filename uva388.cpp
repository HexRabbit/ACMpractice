#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
using namespace std;
int main()
{
	string s1;
	string s2;
	vector<int> a1;
	vector<int> a2; 
	vector<int> ans;
	vector<int> temp;
	int len;
	while(1){
	a1.resize(0);
	a2.resize(0);
	ans.resize(0);
	temp.resize(0);
	cin >> s1;
	if(cin >> s2 == EOF) return 0;
	s1.length() > s2.length() ? len = s1.length() : len = s2.length();
	int rlen;
	unsigned long long int result=stoll(s1)*stoll(s2);
	rlen = to_string(result).length();
	if(len>=rlen){
		cout<<setw(len)<<s1<<endl;
		cout<<setw(len)<<s2<<endl;
	}else
	{
		cout<<setw(rlen)<<s1<<endl;
		cout<<setw(rlen)<<s2<<endl;
	}
	for(int i=0;i<rlen-len;i++) printf(" ");
	for(int i=0;i<len;i++) printf("-");
	printf("\n");
	for(int i=0;i<s1.length();i++)
	{
		a1.push_back(s1[s1.length()-1-i]-'0');
	}
	for(int i=0;i<s2.length();i++)
	{
		a2.push_back(s2[s2.length()-1-i]-'0');
	}
	int cnt=0;
	if(stoll(s1) && stoll(s2) > 0){

	for(int j=0;j<a2.size();j++)
	{
		if(stoll(s1)*a2.at(j)){
			if(a2.at(j)&&len>=rlen) cout<<setw(len-j)<<stoll(s1)*a2.at(j)<<endl; //setw count 
			else cout<<setw(rlen-j)<<stoll(s1)*a2.at(j)<<endl; //setw count 
			cnt++;
		}
	}
	if(cnt>1){
		for(int i=0;i<rlen;i++)
		{
			cout<<"-";
		}
		printf("\n%llu\n",result);
	}
	}
	else cout<<setw(len)<<"0"<<endl;
	cout<<endl;
	}
	return 0;
	}
