#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

const int SIZE=8;
int x[SIZE]={0};
int y[SIZE]={0};
int board[SIZE][SIZE];
int map[SIZE][SIZE];
vector<int> sum;

void setpoint(int a,int b,int total);
int main(int argc, char const *argv[])
{
	int count;
	cin >> count;
	for(int j=0;j<count;j++){
		for(int i=0;i<SIZE;i++)
			for(int j=0;j<SIZE;j++)
				map[i][j]=0;
		sum.resize(0);
		for(int i=0;i<SIZE;i++)x[i]=0;
		for (int i = 0; i < SIZE; ++i)
		{
			for (int k = 0; k < SIZE; ++k)
			{
				cin >> board[i][k];
			}
		}
		for (int i = 0; i < SIZE; ++i)
		{
			x[i]=1;
			y[0]=1;
			map[i][0]=1;
			setpoint(i,0,board[i][0]);
			map[i][0]=0;
			x[i]=0;
			y[0]=0;
		}
#ifdef DEBUG
		cout<< sum.size();
#endif
		cout << setw(5) << *max_element(sum.begin(),sum.end()) << endl;	
	}

	return 0;
}

void setpoint(int a,int b,int total){
	if (b==SIZE-1)
	{
		sum.push_back(total);
		return;
	}
	for (int i = 0;i<SIZE;i++)
	{
		int cnt=0;
		if (x[i]==0)
		{
			for(int j=b-1,k=1;j>=0 && i-k>=0;j--,k--) {if(map[i-k][j] == 1) cnt++;}
			for(int j=b-1,k=1;j>=0 && i+k<SIZE;j--,k++) {if(map[i+k][j] == 1) cnt++;}
			if(cnt==0){
				x[i]=1;
				y[b+1]=1;
				map[i][b+1]=1;
				setpoint(i,b+1,total+board[i][b+1]);
				map[i][b+1]=0;
				x[i]=0;
				y[b+1]=0;
			}
		}
		
	}
}
