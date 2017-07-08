#include<bits/stdc++.h>
#define mod 1908
int c[10000];
int fun2(int n)
{
	int sum=0;
	for(int i=0;i<=n-1;i++)
	{
		sum=(sum%mod+(c[i]%mod*c[n-1-i]%mod)%mod)%mod;
	}
	return sum;
}
int fun(int n)
{
	if(n==0)
	return c[0]=1;
	return c[n]=fun2(n);
}
int st[1005];
int main()
{
//	int n=4;
//	scanf("%d",&n);
	for(int i=0;i<=1000;i++)
	st[i]=fun(i);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",st[n]);
	}
	return 0;
} 
