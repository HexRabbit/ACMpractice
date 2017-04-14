#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int main()
{
	unsigned long long total[200];
	int a[2]={2,4};
	int C;
	cin >> C;
	while(C--)
	{
		memset(total,0,200*sizeof(unsigned long long));
		total[0]=1;
		int max;
		cin >> max;
		for(int i=a[0],j=a[1];i<=max || j<=max; ++i,++j)
		{
			if(i <= max && total[i-a[0]]) total[i]+=total[i-a[0]];
			if(j <= max && total[j-a[1]]) total[j]+=total[j-a[1]];
		}
		cout << total[max] << endl;
	}

	return 0;
}
