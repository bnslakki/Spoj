#include "bits/stdc++.h"
using namespace std;
map<ll, ll>mp;
ll arr[100007];
int main()
{
	//INPUT;
	ll t;
	scanf("%lld", &t);
	for (ll k = 1; k <= t;k++)
	{
		ll x;
		scanf("%lld", &x);
		ll n;
		scanf("%lld", &n);
		
		ll sz = 0;
		ll val;
		for (size_t i = 0; i < n; i++)
		{
			scanf("%lld", &val);
			if (mp[val] == 0)
			{
				arr[sz] = val;
				sz++;
				mp[val] = 1;
			}
			else
			{
				mp[val]++;
			}
		}
		sort(arr, arr + sz);
		/*for (size_t i = 0; i < sz; i++)
		{
			printf("%lld %lld\n", arr[i],mp[arr[i]]);
		}*/
		ll c = 0;
		for (size_t i = 0; i < sz; i++)
		{
			if (binary_search(arr+ i + 1, arr+sz, x - arr[i]))
			{
			//	printf("%lld %lld\n", arr[i], x - arr[i]);
				c = c + mp[arr[i]] * mp[(x - arr[i])];
			}
		}
		if (x % 2 == 0)
		{
			ll d = x / 2;
			ll temp=0;
			if (binary_search(arr, arr + sz, d))
			{
				temp = mp[d];
			}
			if (temp != 0)
			{
				c += ((temp)*(temp - 1)) / 2;
			}
		}
		printf("%lld. %lld\n", k, c);
		mp.clear();
	}
	return 0;
} 
