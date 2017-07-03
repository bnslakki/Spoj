#include "bits/stdc++.h"
using namespace std;
 
const int maxn=1e5+5;
 
vector<int>g[maxn],gr[maxn];
vector<int>order;
set<int>component;
bool visit[maxn];
int ans[maxn];
 
void dfs1(int u){
	visit[u]=1;
	for(int i=0;i<g[u].size();i++){
		if(!visit[g[u][i]]){
			dfs1(g[u][i]);
		}
	}
	order.push_back(u);
}
void dfs2(int u){
	visit[u]=1;
	component.insert(u);
	for(int i=0;i<gr[u].size();i++){
		if(!visit[gr[u][i]]){
			dfs2(gr[u][i]);
		}
	}
}
int main(){
	//freopen("t.txt","r",stdin);
	int n,m,u,v;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		//u--,v--;
		g[u].push_back(v);
		gr[v].push_back(u);
	}
	memset(visit,0,sizeof visit);
	for(int i=0;i<n;i++){
		if(!visit[i])dfs1(i);
	}
	memset(visit,0,sizeof visit);
	for(int i=0;i<n;i++){
		if(!visit[order[n-1-i]]){
			dfs2(order[n-1-i]);
			for(auto j:component){
				ans[j]=*component.begin();
			}
			component.clear();
		}
	}
	for(int i=0;i<n;i++)printf("%d\n",ans[i]);
} 
