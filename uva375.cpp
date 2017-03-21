#include <cstdio>
#include <cmath>

int main(int argc, char const *argv[])
{
	int count;
	scanf("%d",&count);
	for (;count--;){
		const double pi = 2*asin(1);
		double b,h,sum=0,temp;
		scanf("%lf %lf",&b,&h);
		while(1){
			double l=sqrt(pow(b/2,2)+pow(h,2));
			double r=(b*h)/(2*l+b);
			if(r<0.000001) break;
			sum+=2*pi*r;
			temp=h-2*r;
			b=b*temp/h;
			h=temp;
		}
		printf("%13.6f\n", sum);
		if(count) printf("\n");
	}

	return 0;
}
