#include <bits/stdc++.h>
using namespace std;
int d[76];
int dp(int p){
	if(~d[p]) return d[p];
	else return d[p]=(dp(p-2)+dp(p-3));
}
int main()
{
	memset(d,-1,sizeof(d));
	int n;
	d[1]=1;d[2]=2;d[3]=2;
	while(scanf("%d",&n)!=EOF) printf("%d\n",dp(n));

}
