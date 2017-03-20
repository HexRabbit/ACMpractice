#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;
int main(int argc, char const *argv[])
{
	vector<int> a;
	vector<int> b;
	string s1;
	string s2;
	while(1){
	cin >> s1;
	cin >> s2;
	a.resize(0);
	b.resize(0);
	if(s1=="0" and s2=="0") return 0;
	for (int i = s1.length()-1; i >= 0; --i)
	{
		a.push_back(s1[i]-'0');
	}
	for (int i = s2.length()-1; i >= 0; --i)
	{
		b.push_back(s2[i]-'0');
	}
	if(a.size()>b.size()) b.resize(a.size(),0);
	else if(b.size()>a.size()) a.resize(b.size(),0);
	int temp=0,carry=0;
	for (int i = 0; i < a.size(); ++i)
	{
		if (a.at(i)+b.at(i)+temp>=10)
		{
			carry++;
			temp=1;
		}
		else temp=0;
	}
	if(carry==0) cout << "No carry operation." <<endl;
	else if(carry==1)cout << carry << " carry operation." <<endl;
	else cout << carry << " carry operations." <<endl;
	}
}
