#include "bits/stdc++.h"
using namespace std;
int prime[10000004];
void sieve()
{
	int n = 10000004;
	for (int p = 2; p*p <= n; p++)
	{
		if (!prime[p])
		{
			for (int i = p*p; i <= n; i += p)
			{
				if(!prime[i])
				prime[i] = p;
			}
		}
	}
}
void solve(int n)
{
	while (prime[n]!=0&&n%prime[n]==0)
	{
		printf(" x %d", prime[n]);
		if (prime[n] == 0)break;
		n /= prime[n];
	}
	printf(" x %d", n);
}
int main()
{
	//READ;
	//WRITE;
	sieve();
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		if (n == 1)
		{
			printf("1");
		}
		else
		{
			printf("1");
			solve(n);
		}
		printf("\n");
	}
	return 0;
} 
