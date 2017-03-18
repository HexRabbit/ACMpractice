#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	vector<bool> prime;
	prime.resize(100000001,true);
	for(int i=2;i<10001;i++){
		if(prime.at(i)==true){
			for(int j=2;i*j<100000001;j++){
				prime.at(i*j)=false;
			}
		}
	}
#ifdef DEBUG
	for (int i = 0; i < prime.size(); ++i)
	{
		if(prime.at(i)==true) printf("%d\n", i);
	}
#endif
	for(int i=0;i<100000;i++)
	{
		int num,a=1;
		scanf("%d",&num);
		for (int j = num/2; j >= 0; --j)
		{
			if (prime.at(j)==true && prime.at(num-j)==true) {
				printf("%d is the sum of %d and %d.\n", num,j,num-j);
				a--;
				break;
			}
		}
		if (a) printf("%d is not the sum of two primes!\n", num);
	}
	return 0;
}

