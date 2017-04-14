#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
using namespace std;
vector<int> rec;
vector<int> glo_rec;
vector<pair<int,int>> cir;
int mx=0,cnt=0;
struct Child
{
	int next;
	vector<int>prev;
};
vector<Child> child;
void traverse(int,int);
int main()
{
	int C,a=1;
	cin >> C;
	while(C--)
	{
		int total;
		int temp;
		cin >> total;
		child.resize(0);
		child.resize(total);
		for(int i=0; i<total; ++i)
		{
			cin >> child[i].next;
			child[i].next--;
			child[child[i].next].prev.push_back(i);
		}
		mx=0;cnt=0;
		rec.assign(total,0);
		glo_rec.assign(total,0);
		cir.resize(0);
		for(int i=0; i<total; ++i)
		{
			if(child[i].prev.empty())
			{
				traverse(i,-1);
				mx=max(mx,cnt);
				cnt=0;
				rec.assign(total,0);
			}
		}
		for(int i=0; i<total; ++i)
		{
			if(glo_rec[i]==0) {
				traverse(i,-1); //possibliy be two element circle,but doesn't matter
				mx=max(mx,cnt);
				cnt=0;
				rec.assign(total,0);
			}
		}
		int connect=0;

		for(auto i=cir.begin(); i!=cir.end(); ++i)
		{
			for(auto j=i+1; j != cir.end(); ++j)
			{
				if(child[i->first].next==j->first)
				{
//					cout << i->first << ": " << i->second << endl;
//					cout << j->first << ": " << j->second << endl;
					connect+=(i->second+j->second);
					//					mx=max(mx,i->second+j->second);
				}
			}
		}
		mx=max(mx,connect);
		printf("Case #%d: %d\n",a,mx);
		a++;
	}
}

void traverse(int node,int goal)
{
	cnt++;
	rec[node]=1;
	glo_rec[node]=1;
	if(goal != -1) // count circle
	{
		if(node != goal) traverse(child[node].next,goal);
		else return;
	}
	else if(child[child[node].next].next==node) //two element circle
	{
		int q=1;
		for(int i=0; i<cir.size(); ++i)
		{
			if(cir[i].first==node){q=0;cir[i].second=max(cnt,cir[i].second);break;}
		}
		if(q) cir.push_back(make_pair(node,cnt));
		cnt++;
		return;
	}
	else if(rec[child[node].next]==1) //detect circle
	{
		cnt=0;
		traverse(child[node].next,node);
	}
	else
	{
		traverse(child[node].next,-1);
	}
}
