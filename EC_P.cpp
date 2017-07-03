#include "bits/stdc++.h"
using namespace std;
 
const int maxn=707;
vector<int>arr[maxn];
vector<pair<int,int>>bridge;
bool visit[maxn];
int parent[maxn];
int low[maxn];
int disc[maxn];
 
void Bridge(int u){
	static int time=0;
	visit[u]=1;
	disc[u]=low[u]=++time;
	for(int i=0;i<arr[u].size();i++){
		int v=arr[u][i];
		if(!visit[arr[u][i]]){
			parent[v]=u;
			Bridge(v);
			low[u]=min(low[u],low[v]);
			if(low[v]>disc[u]){
				if(u<=v)bridge.push_back({u,v});
				else bridge.push_back({v,u});
			}
		}
		else if(v!=parent[u])low[u]=min(low[u],disc[v]);
	}
}
 
int main(){
	//freopen("t.txt","r",stdin);
	int t,n,m,u,v,tc=1;
	for(scanf("%d",&t);t--;){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n+2;i++)arr[i].clear();
		memset(visit,0,sizeof visit);
		memset(parent,-1,sizeof parent);
		bridge.clear();
		for(int i=0;i<m;i++){
			scanf("%d%d",&u,&v);
			u--,v--;
			arr[u].push_back(v);
			arr[v].push_back(u);
		}
		for(int i=0;i<n;i++){
			if(!visit[i]){
				Bridge(i);
			}
		}
		sort(bridge.begin(),bridge.end());
		printf("Caso #%d\n",tc++);
		if(bridge.size()){
			printf("%d\n",bridge.size());
			for(auto i:bridge){
				cout<<i.first+1<<" "<<i.second+1<<endl;
			}
		}
		else printf("Sin bloqueos\n");
	}	
} 
