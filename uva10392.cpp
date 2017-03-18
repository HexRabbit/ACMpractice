#include<iostream>
#include<cstdio>
#include<vector>
using namespace std; 
int main(){
	vector<int> prime;
	int cnt;
	long long int a;
	prime.push_back(2);
	prime.push_back(3);
	for(int i=5,k=2;i<1000000;i+=k,k=6-k){
		cnt=0;
		for(int j=2;j*j<i;j++){
			if(i%j==0) {
				cnt++;break;
			}
		}
		if(cnt==0) prime.push_back(i); 
	}
	int r=0;
	for(;scanf("%lld",&a)&&a>0;r++){
		if(r) printf("\n");
		for(int i=0;i<prime.size() && a>1;i++){ //有沒有少條件?
			if(a%prime.at(i)==0) {
				printf("    %d\n",prime.at(i));
				a=a/prime.at(i);
				i--;
			}
		}
		if(a!=1) printf("    %lld\n",a);
	}
	printf("\n");
	return 0;
}

