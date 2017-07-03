#include "bits/stdc++.h"
using namespace std;
 
const int maxn=1e4+4;
vector<int>arr[maxn];
bool visit[maxn];
int parent[maxn];
int low[maxn];
set<int>ap;
int disc[maxn];
 
void ArticulationPoint(int u){
	static int time=0;
	int child=0;
	visit[u]=1;
	disc[u]=low[u]=++time;
	for(int i=0;i<arr[u].size();i++){
		int v=arr[u][i];
		if(!visit[arr[u][i]]){
			child++;
			parent[v]=u;
			ArticulationPoint(v);
			low[u]=min(low[u],low[v]);
			if(parent[u]==-1&&child>1)ap.insert(u);
			if(parent[u]!=-1&&low[v]>=disc[u])ap.insert(u);
		}
		else if(v!=parent[u])low[u]=min(low[u],disc[v]);
	}
}
int main(){
	//freopen("t.txt","r",stdin);
	int n,m,u,v;
	while(scanf("%d%d",&n,&m)){
		if(!n&&!m)break;
		memset(parent,-1,sizeof parent);
		memset(visit,0,sizeof visit);
		for(int i=0;i<n+1;i++)arr[i].clear();
		for(int i=0;i<m;i++){
			scanf("%d%d",&u,&v);
			arr[u].push_back(v);
			arr[v].push_back(u);
		}
		for(int i=0;i<n;i++){
			if(!visit[i]){
				ArticulationPoint(i);
			}
		}
		printf("%d\n",ap.size());
		ap.clear();
	}
} 
