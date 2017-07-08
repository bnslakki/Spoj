#include<bits/stdc++.h>
#define pi 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int  n;
		scanf("%lld",&n);
		if(n==0)
		printf("1\n");
		else
		{
		double a=(log(2.0*pi*n))/2.0+n*(log(n)-1.0);
		double b=a/log(10);
		long long int ans=(long long int)b+1;
		printf("%lld\n",ans);
		}
	}
	return 0;
} 
