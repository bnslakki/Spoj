#include<bits/stdc++.h>
#define pi 3.141592654
int main()
{
	double n;
	while(scanf("%lf",&n))
	{
		if(n==0)
		{
			break;
		}
		printf("%0.2lf\n",(n*n)/(2*pi));
	}
	return 0;
} 
