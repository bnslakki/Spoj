#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
int fun(int a,int b,int c){
    long long x=1,y=a;
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%c;
        }
        y = (y*y)%c; 
        b /= 2;
    }
    return x%c;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		ll n,temp,ans;
		scanf("%lld",&n);
		if(n==1)
		{
			int t2=1;
			printf("Case %d: %d\n",i,t2);
		}
		else
		{
			temp=fun(2,n-2,mod);
			ans=((n+1)*temp)%mod;
			printf("Case %d: %lld\n",i,ans);
		}
	}
	return 0;
}
 
