#include "bits/stdc++.h"
#define ll unsigned long long
#define MAXN 555555555555555
using namespace std;
ll sum(ll n) {
	ll ans = 0;
	int x = 0;
	for (int i = __lg(n); i >= 0; --i)
		if (n & 1LLU << i)
			ans += ((1LLU << i) >> 1) * i + 1 + (1LLU << i) * x++;
	return ans;
}
ll Binary_Search(ll n)
{
	ll low = 0;
	ll high = n+1;
	ll mid;
	while (low <= high)
	{
		mid = ((low + high) >> 1);
		ll temp = sum(mid);
		if (temp == n)
		{
			return mid;
		}
		else if (n > temp)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return -1;
}
int main()
{
//	READ;
	int t;
	scanf("%d", &t);
	while (t--)
	{
		ll n;
		scanf("%llu", &n);
		ll ans = Binary_Search(n);
		if (ans == -1)
		{
			printf("Does Not Exist.\n");
		}
		else
		{
			printf("%llu\n", ans);
		}
	}
	return 0;
} 
