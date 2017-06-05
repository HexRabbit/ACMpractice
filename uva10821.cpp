#include<bits/stdc++.h>
int N,H;
void BST(int now,int l,int r)
{
	if(now>H || l==r) return;
	int i;
	int lim=(1<<(H-now))-1;
	for(i=l;i<r;i++) {
		if((r-1)-i <= lim) {
			printf(" %d",i);
			break;
		}
	}
	BST(now+1,l,i);
	BST(now+1,i+1,r);
}

int main(int argc,char *argv[])
{
	int a=1;
	while(scanf("%d%d",&N,&H) && N)
	{
		int mx=(1<<H)-1;
		if(N>mx)printf("Case %d: Impossible.\n",a);
		else {
			printf("Case %d:",a);
			BST(1,1,N+1);
			printf("\n");
		}
		a++;
	}

	return 0;
}
