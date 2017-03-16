#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
class Cow{
	public:
	int index;
	int first;
	int second;
};
bool compare(Cow a1,Cow a2) {return a1.first<a2.first;}
bool compare2(Cow a1,Cow a2) {return a1.second<a2.second;}
int main(){
	vector<Cow> cows;
	int count,r2;
	scanf("%d%d",&count,&r2);
	cows.resize(count);
	for(int i=0;i<count;i++)
	{
		scanf("%d%d",&cows.at(i).first,&cows.at(i).second);
		cows.at(i).index=i+1;
	}
	sort(cows.begin(),cows.end(),compare);
	sort(cows.begin(),cows.begin()+r2,compare2);
	printf("%d",cows.at(0).index);
	return 0;
}
