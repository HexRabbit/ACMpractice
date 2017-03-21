#include <vector>
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
struct Case{int cost;int mb;};
class T
{
public:
	T(){
		b=false;
		tcost=0;
//		for(int i=2;i--;){type[i]=0;} adding this will be detected as virus ???
	}
	bool b;
	int tcost;
	int type[2]={0,0};
};
bool compare(Case c1,Case c2) { return c1.mb<c2.mb; }
int main(int argc, char const *argv[])
{
	int total;
	Case a[2];
	vector<T> test;
	while(cin >> total && total!=0)
	{
		test.resize(0);
		test.resize(total+1,T());
		test.at(0).b=true;
		for (int i = 0; i < 2; ++i)
		{
			cin >> a[i].cost;
			cin >> a[i].mb;
		}
		sort(a,a+2,compare);
		for(int j=0;j<2;j++)
		{
			for (int i = a[j].mb; i <= total; i++)
			{
				if (test.at(i-a[j].mb).b) 
				{
					if(test.at(i).b==true && test.at(i-a[j].mb).tcost+a[j].cost < test.at(i).tcost)
					{
						test.at(i).tcost = test.at(i-a[j].mb).tcost+a[j].cost;
						for (int k = 0; k < 2; ++k)
						{
							test.at(i).type[k] = test.at(i-a[j].mb).type[k];
						}
						test.at(i).type[j]++;
					}
					else if(test.at(i).b==false){
						test.at(i).b=true;
						for (int k = 0; k < 2; ++k)
						{
							test.at(i).type[k] = test.at(i-a[j].mb).type[k];
						}
						test.at(i).type[j]++;
						test.at(i).tcost = test.at(i-a[j].mb).tcost+a[j].cost;
					}

				}
			}
		}
		if(!test.at(total).b) {
			cout<<"failed"<<endl;
		}
		else {
			cout << test.at(total).type[0] << " " << test.at(total).type[1] << endl;
		}		
	}
	return 0;
}
