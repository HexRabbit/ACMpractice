#include <iostream>
#include <cstdio>
using namespace std;
char cake[25][25];
void place(int,int,int);
int main()
{
	int C,aa=1;
	cin >> C;
	while(C--)
	{
		int row;
		int col;
		cin >> row;
		cin >> col;
		for(int i=0; i<row; ++i)
		{
			for(int j=0; j<col; ++j)
			{
				scanf(" %c",&cake[i][j]);
			}
		}
		for(int i=0; i<row; ++i)
		{
			for(int j=0; j+1<col; ++j)
			{
				if(cake[i][j]!='?' && cake[i][j+1]=='?') cake[i][j+1]=cake[i][j];
			}
			for(int j=col-1; j-1>=0; --j)
			{
				if(cake[i][j] != '?'&& cake[i][j-1]=='?') cake[i][j-1]=cake[i][j];
			}
		}
		for(int i=0; i<col; ++i)
		{
			for(int j=0; j+1<row; ++j)
			{
				if(cake[j][i]!='?'&& cake[j+1][i]=='?') cake[j+1][i]=cake[j][i];
			}
			for(int j=row-1; j-1>=0; --j)
			{
				if(cake[j][i]!='?'&& cake[j-1][i]=='?') cake[j-1][i]=cake[j][i];
			}
		}
		printf("Case #%d:\n",aa);aa++;
		for(int i=0; i<row; ++i)
		{
			for(int j=0; j<col; ++j)
			{
				cout << cake[i][j];
			}
			cout << endl;
		}
	}
}

void place(int p,int max,int w)
{
	if(w==0)
	{
		for(int i=0; i<max; ++i)
		{
			if(cake[p][i]!='?')
			{
				int temp=p;
				while(temp>0 && cake[temp-1][i]=='?') {cake[temp-1][i]=cake[temp][i];temp--;}
				temp=p;
				while(temp<max && cake[temp+1][i]=='?') {cake[temp+1][i]=cake[temp][i];temp++;}
			}
		}
	}
	else
	{
		for(int i=0; i<max; ++i)
		{
			if(cake[i][p]!='?')
			{
				int temp=p;
				while(temp>0 && cake[i][temp-1]=='?') {cake[i][temp-1]=cake[i][temp];temp--;}
				temp=p;
				while(temp<max-1 && cake[i][temp+1]=='?') {cake[i][temp+1]=cake[i][temp];temp++;}
			}
		}
	}
}
