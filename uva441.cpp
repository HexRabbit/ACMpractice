#include <iostream>
#include<vector>
using namespace std;
void recursive(vector<int>&nums ,int point,int count,vector<int>&save,int first);
int main(int argc, char const *argv[])
{
	int size;
	vector<int> nums;
	vector<int> save;
	int a=0;
	while(cin>>size && size){
		nums.resize(0);
		save.resize(0);
		for (int i = 0; i < size; ++i)
		{
			nums.push_back(0);
			cin >> nums.at(i);
		}
		if(a) cout<<'\n';
		recursive(nums,-1,0,save,1);
		a++;
	}
	return 0;
}

void recursive(vector<int>&nums ,int point,int count,vector<int>&save,int first)
{
	if(count==6){ 
		for (int i = 0; i < count; ++i)
		{
			if(i>0) cout<< " ";
			cout<<save.at(i);
		}
		cout<<endl;
		return;
	}
	if(first){
		for (int i = 0; i < nums.size()-6+1; ++i)
		{
			save.push_back(nums.at(i));
			recursive(nums,i,1,save,0);
			save.pop_back();
		}
		return;
	}
	for (int i = point+1; i < nums.size()-(6-count)+1; ++i)
	{
		save.push_back(nums.at(i));
		recursive(nums,i,count+1,save,0);
		save.pop_back();
	}
	return;
}
