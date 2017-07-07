#include<bits/stdc++.h>

#define ll long long
#define pii pair<ll,ll>
#define INT64_MAX 1e8

using namespace std;
 
priority_queue<pii, vector<pii>, greater<pii> > q;
vector<pair<ll, ll> >edge[10100];
ll Distance[10100];
 
void INITIALIZE_SINGLE_SOURCE(ll source,ll vertex)
{
	for (ll i = 1; i <= vertex; i++)
	{
		Distance[i] = INT64_MAX;
	}
	Distance[source] = 0;
}
void RELAX(ll u,ll v,ll w)
{
	if (Distance[v]>w+Distance[u])
	{
		Distance[v] = Distance[u] + w;
		q.push(pii(v, Distance[v]));
	}
}
void DIJKSTRA(ll source,ll vertex)
{
	ll u, v, w;
	INITIALIZE_SINGLE_SOURCE(source, vertex);
	q.push(pair<ll, ll>(source, 0));
 
	while (!q.empty())
	{
		u = q.top().first;
		q.pop();
		for (ll i = 0; i < edge[u].size(); i++)
		{
			v = edge[u][i].first;
			w = edge[u][i].second;
			RELAX(u, v, w);
		}
	}
}
int main()
{
//	input
	ll n,e;
	scanf("%lld",&e);
	for(ll i=0;i<=600;i++)
	{
	    Distance[i] = 0;
	    edge[i].clear();
	}
	ll maxi=-1;
	while(e--)
	{
        ll u,v,w;
	    scanf("%lld%lld%lld",&u,&v,&w);
	    maxi=max(maxi,max(u,v));
	    edge[u+1].push_back(pair<ll, ll>(v+1, w));
	    edge[v+1].push_back(pair<ll, ll>(u+1, w));
	}
	n=maxi+1;
//	printf("%lld\n",n);
	ll source,dest;
	scanf("%lld",&source);
	DIJKSTRA(source+1, n);
	int query;
	scanf("%lld",&query);
	while(query--)
	{
	    scanf("%lld",&dest);
	    if(dest+1>n)
	    printf("NO PATH\n");
	    else
	    {
	        if(Distance[dest+1]==INT64_MAX)
            printf("NO PATH\n");
           	else
	        printf("%lld\n",Distance[dest+1]);
	    }	
    }
	return 0;
} 
