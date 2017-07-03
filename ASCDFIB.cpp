#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
#define ll int
#define mod 100000
using namespace std;
ll fibo[1100006];  // store fibo no up to 10e6
ll dp[1100006];
ll nth_fib(ll n)
{
	if (dp[n] != 0)
		return dp[n];
	if (n == 1)
		return dp[n]=0;
	if (n == 2)
		return dp[n] = 1;
	else
		return dp[n] = (nth_fib(n - 1) + nth_fib(n - 2) ) % mod;
}
void pre()
{
	for (ll n = 1; n <= 1100004; n++)
	{
		fibo[n-1] = nth_fib(n);
		//printf("%lld\n", nth_fib(n));
	}
}
ll cs[100004];
int main()
{
	pre();
//	freopen("t.txt", "r", stdin);
	ll t, k = 0;
	scanf("%d", &t);
	for (ll j = 1; j <= t; j++)
	{
		k = 0;
		ll a, b;
		scanf("%d%d", &a, &b);
		for (ll j = 0; j < 100000; j++) cs[j] = 0;
		printf("Case %d:", j);
		for (ll i = a; i <= a + b; i++)
		{
			cs[fibo[i-1]]++;
		}
		int flag = 0;
		for (ll i = 0; ; i++)
		{
			if (cs[i] != 0)
			{
				for (ll l = 0; l < cs[i]; l++)
				{
					printf(" %d", i);
					k++;
					if (k == 100 || k == b + 1)
					{
						flag = 1;
						break;
					}
				}
			}
			if (flag == 1)
				break;
		}
		printf("\n");
	}
	return 0;
} 
