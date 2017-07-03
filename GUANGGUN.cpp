#include<bits/stdc++.h>
int main()
{
	long long n;
	while(scanf("%lld",&n)!=EOF)
	{
		printf("%lld\n",(n/9)*81+((n%9)*(n%9)));
	}
} 
