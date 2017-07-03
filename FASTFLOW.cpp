#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
const int maxn=5005;
 
struct edge{
	int v;
	int flow,c;
	int rev;
};
 
vector<edge>arr[maxn];
int level[maxn];
int ptr[maxn];
 
inline void addedge(int u,int v,int w){
	edge a{v,0,w,arr[v].size()};
	edge b{u,0,w,arr[u].size()};
	arr[u].push_back(a);
	arr[v].push_back(b);
}
 
inline bool bfs(int s,int t){
	memset(level,-1,sizeof level);
	level[s]=0;
	queue<int>q;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(ll i=0;i<arr[u].size();i++){
			if(level[arr[u][i].v]<0&&arr[u][i].flow<arr[u][i].c){
				level[arr[u][i].v]=level[u]+1;
				q.push(arr[u][i].v);
			}
		}
	}
	return level[t]<0?0:1;
}
 
inline int dfs(int u,int flow,int t){
	if(u==t)return flow;
	for(;ptr[u]<arr[u].size();ptr[u]++){
		if(level[arr[u][ptr[u]].v]==level[u]+1&&arr[u][ptr[u]].flow<arr[u][ptr[u]].c){
			int cur_flow=min(flow,arr[u][ptr[u]].c-arr[u][ptr[u]].flow);
			int tm_flow=dfs(arr[u][ptr[u]].v,cur_flow,t);
			if(tm_flow>0){
				arr[u][ptr[u]].flow+=tm_flow;
				arr[arr[u][ptr[u]].v][arr[u][ptr[u]].rev].flow-=tm_flow;
				return tm_flow;
			}
		}
	}
	return 0;
}
 
inline ll Dinic(int s,int t){
	if(s==t)return -1;
	ll total_flow=0;
	while(bfs(s,t)){
		memset(ptr,0,sizeof ptr);
		while(int flow=dfs(s,INT_MAX,t)){
			total_flow+=flow;
		}
	}
	return total_flow;
}
int main(){
	//freopen("t.txt","r",stdin);
	int n,m,u,v,w;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w);
	}
	printf("%lld\n",Dinic(1,n));
} 
