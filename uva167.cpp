#include <cstdio>
#include <iostream>
int map[8][8], max, rec[8]={0};
void solve(int r,int sum);
bool check(int r,int c);
int main(int argc, char const *argv[])
{
	int cnt;
	scanf("%d",&cnt);
	while(cnt--)
	{
		max=0;
		for (int i = 0; i < 8; ++i)
			for (int j = 0; j < 8; ++j)
				scanf("%d",&map[i][j]);
		solve(0,0);
		printf("%5d\n", max);
	}
	return 0;
}

void solve(int r,int sum)
{
	if(r==8) 
		if(sum > max) max=sum;
	for (int i = 0; i < 8; ++i)
	{
		if(check(r,i)) 
		{
			rec[i]=r+1;// +1 for recognize
			solve(r+1,sum+map[r][i]);
			rec[i]=0;
		}
	}
}

bool check(int r,int c)
{
	if(rec[c]) return false;
	for (int i = 0; i < 8; ++i)
	{
		if (rec[i] != 0 && (i+rec[i]-1 == c+r || i-(rec[i]-1) == c-r))
		{
			return false;
		}
	}
	return true;
}
