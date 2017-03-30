#define func(x) (a*exp(-x)+b*sin(x)+c*cos(x)+d*tan(x)+e*x*x+f)
#include <cmath>
#include <cstdio>
using namespace std;
int main(){
	int a,b,c,d,e,f;
		while(scanf("%d",&a)==1)
		{
			scanf("%d%d%d%d%d",&b,&c,&d,&e,&f);
			const double eps=0.0000001;
			double left=0;
			double right=1;
			double temp=1;
			if(func(left)*func(right) <= 0)
			{
				while(abs(func(temp)) > eps)
				{
					temp=(right+left)/2;
					if(func(temp) > 0) left=temp;//coz func decreace in range 0-1
					else  right=temp;
				}
				printf("%.4f\n",temp);
			}
			else printf("No solution\n");
		}
}

