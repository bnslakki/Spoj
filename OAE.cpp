#include<bits/stdc++.h>
#define ba 157080  // mmi
#define mod 314159
#define ll long long int
ll power(ll a, ll b, ll c)
{
	long long x = 1, y = a; 
	while (b > 0) {
		if (b % 2 == 1) {
			x = (x*y) % c;
		}
		y = (y*y) % c; 
		b /= 2;
	}
	return x%c;
}
int main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		ll n,a;
		scanf("%lld",&n);
	 	a=(power(10,n,mod)+power(8,n,mod))%mod;
		printf("%lld\n",(a*ba)%mod);
	}
	return 0;
} 
