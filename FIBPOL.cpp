#include "bits/stdc++.h"
using namespace std;
ll store[30];
ll fib_no[100];
void fib()
{
	fib_no[0] = 0;
	fib_no[1] = 1;
	for (size_t i = 2; i < 80; i++)
	{
		fib_no[i] = fib_no[i - 1] + fib_no[i - 2];
	}
}
void pre()
{
	fib();
	ll k = 0;
	for (size_t i = 1; i < 45; i=i+2)
	{
		store[k] = fib_no[i + 1] * fib_no[i + 2];
		k++;
	}
	//printf("%d\n", k);
}
int main()
{
	pre();
	int t;
	scanf("%d", &t);
	while (t--)
	{
		ll n;
		scanf("%lld", &n);
		if (!n)
			printf("1\n");
		else
		{
			if (binary_search(store, store + 22, n))
				printf("1\n");
			else
			{
				printf("0\n");
			}
		}
	}
	return 0;
} 
