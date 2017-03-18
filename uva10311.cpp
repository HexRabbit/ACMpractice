#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int seek2num(int a,vector<int> &prime);
int main()
{
	bool prime[100000001]={true};
	int cnt;
	int a;
	for(int i=2;i<10001;i++){
		if(prime[i]==true){
			for(int j=2;i*j<100000001;j++){
				prime[i*j]=false;
			}
		}
		
	}
	for(int i=0;i<100000;i++)
	{
		int num,a=1;
		scanf("%d",&num);
		for (int j = seek2num(num/2,prime); j >= 0; --j)
		{
			if (prime.at(seek2num(num - prime.at(j),prime)) == num - prime[j])) {
				printf("%d is the sum of %d and %d.\n", num,num - prime.at(j),prime.at(j));
				a--;
				break;
			}
		}
		if (a) printf("%d is not the sum of two primes!\n", num);
	}
	return 0;
}

