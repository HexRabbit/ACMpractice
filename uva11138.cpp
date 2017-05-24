#include <stdio.h>
#define MAX_BOLTS 1000
#define MAX_NUTS  1000
#include <cstring>
/* global copy of the input data */
int nuts,bolts;
int fits[MAX_BOLTS][MAX_NUTS];
/* data used to match nuts with bolts */
bool check[MAX_BOLTS];
int match[MAX_BOLTS];

bool dfs(int u)
{
	for(int i=0;i<nuts;i++) {
		if(fits[i][u] && !check[i]) {
			check[i]=1;
			if(match[i]==-1||dfs(match[i])) {
				match[i]=u;
				return true;
			}
		}
	}
	return false;
}
void read_input_data(void){
	int n,b;
	scanf("%d%d",&bolts,&nuts);
	for(b=0;b<bolts;b++){
		for(n=0;n<nuts;n++){
			scanf("%d",&fits[b][n]);
		}
	}
}


int main(){
	int cases,caseno;
	scanf("%d",&cases);
	for(caseno=1;caseno<=cases;caseno++){
		int ans=0;
		memset(fits,0,sizeof(fits));
		memset(match,-1,sizeof(match));
		read_input_data();
		for(int i=0;i<bolts;++i) {
			memset(check,0,sizeof(check));
			if(dfs(i)) ans++;
		}
		printf("Case %d: ",caseno);
		printf("a maximum of %d nuts and bolts ",ans);
		printf("can be fitted together\n");
	}
	return 0;
}
