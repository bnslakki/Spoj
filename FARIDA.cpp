#include "bits/stdc++.h"
#define ll long long
using namespace std;
ll arr[10005];
ll dp[10005];
ll n;
ll sum(ll i)
{
	if (dp[i] != -1)
		return dp[i];
	if (i == n)
		return dp[i]=arr[i];
	else if (i + 1 == n)
		return dp[i]=max(arr[i], arr[n]);
	else
	{
		return dp[i]=max(arr[i] + sum(i + 2), sum(i + 1));
	}
}
int main()
{
//	INPUT;
	ll t;
	scanf("%lld", &t);
	for (ll k = 1; k <= t;k++)
	{
		for (size_t i = 0; i < 10004; i++)
		{
			dp[i] = -1;
		}
		scanf("%lld", &n);
		for (size_t i = 1; i <= n; i++)
		{
			scanf("%lld", &arr[i]);
		}
		if (n == 0)
			printf("Case %lld: 0\n", k);
		else
		printf("Case %lld: %lld\n",k, sum(1));
	}
}
 
