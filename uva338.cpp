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
	unsigned long long int q1,q2;
	int len;
	while(1){
	a1.resize(0);
	a2.resize(0);
	ans.resize(0);
	temp.resize(0);
	cin >> q1;
	if(!(cin >> q2)) return 0;
	s1=to_string(q1);
	s2=to_string(q2);
//	if(s1 == "0") return 0;
	s1.length() > s2.length() ? len = s1.length() : len = s2.length();
	int rlen;
	unsigned long long int result=q1*q2;
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
	int check=0;
	for(int k=0;k<a2.size();k++) {if(a2.at(k)==0) check++;} 
	if(stoll(s1) > 0 && stoll(s2) > 0){

	for(int j=0;j<a2.size();j++)
	{
		if(stoll(s1)*a2.at(j)){
			if(a2.at(j)&&len>=rlen) cout<<setw(len-j)<<stoll(s1)*a2.at(j); //setw count 
			else cout<<setw(rlen-j)<<stoll(s1)*a2.at(j); //setw count
			if(a2.size()-check==1) {for(int i=0;i<check;i++) cout<< '0';}
			cout<<endl; 
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
