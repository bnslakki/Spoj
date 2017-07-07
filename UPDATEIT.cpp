#include<bits/stdc++.h>
#define ll long long
ll bitadd[10005];
ll bitmul[10005];
int getnext(ll index)
{
	return index+(index&(-index));
}
void fun(ll pos,ll mul,ll add,ll n)
{
	while(pos<=n)
	{
		bitmul[pos]+=mul;
		bitadd[pos]+=add;
		pos=getnext(pos);
	}
}
void update(ll left,ll right,ll val,ll n)
{
	fun(left,val,-val*(left-1),n);
	fun(right,-val,val*right,n);
}
ll getparent(ll index)
{
	return index-(index&(-index));
}
ll range(ll pos)
{
	ll mul=0;
	ll add=0;
	ll start=pos;
	while(pos>0)
	{
		mul+=bitmul[pos];
		add+=bitadd[pos];
		pos=getparent(pos);
	}
	return mul*start+add;
}
int main()
{
//	freopen("t.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		for(int i=0;i<10005;i++)
		{
			bitadd[i]=0;
			bitmul[i]=0;
		}
		int n,u;
		scanf("%d%d",&n,&u);
		while(u--)
		{
            int p,q;
		    long long v;
		    scanf("%d%d%lld",&p,&q,&v);
		    update(p+1,q+1,v,n);
		}
		int q;
		scanf("%d",&q);
		while(q--)
		{
			int pos;
			scanf("%d",&pos);
			printf("%lld\n",range(pos+1)-range(pos));
		}
	}
	return 0;
} 
