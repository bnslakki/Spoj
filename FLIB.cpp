#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int 
/////////////////////////
ll mul(ll a,ll b,ll c)
{
	ll x=0,y=a%c;
	while(b>0)
	{
		if(b&1)
		{
			x=(x+y)%c;
		}
		y=(y<<1)%c;
		b>>=1;
	}
	return x%c;
}
/////////////////////////
ll mul(ll mat1[2][2],ll mat2[2][2])
{
	ll a=((mat1[0][0]*mat2[0][0])+(mat1[0][1]*mat2[1][0]))%mod;
	ll b=((mat1[0][0]*mat2[0][1])+(mat1[0][1]*mat2[1][1]))%mod;
	ll c=((mat1[1][0]*mat2[0][0])+(mat1[1][1]*mat2[1][0]))%mod;
	ll d=((mat1[1][0]*mat2[0][1])+(mat1[1][1]*mat2[1][1]))%mod;
	mat1[0][0]=a;
	mat1[0][1]=b;
	mat1[1][0]=c;
	mat1[1][1]=d;
	return (mat1[0][0])%mod;
}
/////////////////////////
ll power(ll mat[2][2],ll m)
{
	if(m==0||m==1)
	return 1;
	else
	{
	ll temp[2][2]={{1,1},{1,0}};
	ll ans;
	power(mat,m>>1);
	ans=mul(mat,mat);
	if(m%2!=0)
	ans=mul(mat,temp);
	return ans;
	}
}
/////////////////////////
ll fib(ll n)
{
	ll mat[2][2]={{1,1},{1,0}};
	return power(mat,n-1);
}
////////////////////////
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n;
		int tm;
		scanf("%lld",&n);
		tm=mul(fib(n<<1),fib((n<<1)+1),mod);
//		tm=(fib(2*n)*fib(2*n+1))%mod;
		printf("%d\n",tm);
	}
	return 0;
}   
