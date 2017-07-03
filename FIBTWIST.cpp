#include<bits/stdc++.h>
 
#define ll long long int 
/////////////////////////
inline ll mul(ll a,ll b)
{
	ll x=0,y=a;
	while(b>0)
	{
		if(b&1)
		{
			x=(x+y);
		}
		y=(y<<1);
		b>>=1;
	}
	return x;
}
/////////////////////////
inline ll mul(ll a,ll b,ll c)
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
inline ll muli(ll mat1[2][2],ll mat2[2][2],ll mod)
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
ll power(ll mat[2][2],ll m,ll modu)
{
	if(m==0||m==1)
	return 1;
	else
	{
	ll temp[2][2]={{1,1},{1,0}};
	ll ans;
	power(mat,m>>1,modu);
	ans=muli(mat,mat,modu);
	if(m%2!=0)
	ans=muli(mat,temp,modu);
	return ans;
	}
}
/////////////////////////
ll fib(ll n,ll modu)
{
	ll mat[2][2]={{1,1},{1,0}};
	return power(mat,n-1,modu);
}
////////////////////////
int main()
{
	int t;
//	freopen("t.txt","r",stdin);
	scanf("%d",&t);
	while(t--)
	{
		ll n,modu,temp;
//		printf("%d",fib(5));
		scanf("%lld%lld",&n,&modu);
//		tm=mul(fib(n<<1),fib((n<<1)+1),mod);
		if(n==0)
		printf("0\n");
		else
		{
			temp=(2*fib(n+2,modu)%modu-n%modu-2+modu)%modu;
			printf("%lld\n",temp);
		}
		
	}
	return 0;
}  
