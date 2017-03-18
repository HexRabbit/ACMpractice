#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int SIZE=8;
int x[SIZE]={0};
int board[SIZE][SIZE];
vector<int> sum;

void setpoint(int a,int b,int total);
int main(int argc, char const *argv[])
{
	int count;
	cin >> count;
	for(int j=0;j<count;j++){
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
			setpoint(i,0,board[i][0]);
			x[i]=0;
		}
		cout << *max_element(sum.begin(),sum.end()) << endl;
	}

	return 0;
}

void setpoint(int a,int b,int total){
	if (b==SIZE-1)
	{
		sum.push_back(total);
		return;
	}
	for (int i = 0;;)
	{
		while(i<SIZE&&x[i]==1) i++;
		if (!(i<SIZE)) return;
		x[i]=1;
		setpoint(i,b+1,total+board[i][b+1]);
		x[i]=0;
	}
}