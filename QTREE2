#include "bits/stdc++.h"
using namespace std;
 
const int maxn=10001;
 
vector<pair<int,int>>arr[maxn];
int dist[maxn],parent[maxn],level[maxn],P[maxn][14];
 
void dfs(int s=1,int par=-1,int lev=0){
	level[s]=lev;
	for(int i=0;i<arr[s].size();i++){
		if(arr[s][i].first==par)continue;
		dist[arr[s][i].first]=dist[s]+arr[s][i].second;
		parent[arr[s][i].first]=s;
		dfs(arr[s][i].first,s,lev+1);
	}
}
void pre(int n){
	memset(P,-1,sizeof P);
	for(int i=1;i<=n;i++)P[i][0]=parent[i];
	for(int j=1;1<<j<n;j++){
		for(int i=1;i<=n;i++){
			if(P[i][j-1]!=-1)P[i][j]=P[P[i][j-1]][j-1];
		}
	}
}
int lca(int a,int b){
	if(level[a]<level[b])swap(a,b);
	int step;
	for(step=1;1<<step<=level[a];step++);step--;
	for(int i=step;i>=0;i--){
		if(level[a]-(1<<i)>=level[b])
			a=P[a][i];	
	}
	if(a==b)return a;
	for(int i=step;i>=0;i--){
		if(P[a][i]!=-1&&P[a][i]!=P[b][i])
			a=P[a][i],b=P[b][i];
	}
	return parent[a];
}
int kth(int node,int k){
	int step;
	for(step=1;1<<step<=level[node];step++);step--;
	for(int i=step;i>=0;i--){
		if(level[node]-(1<<i)>=k)
			node=P[node][i];
	}
	return node;
}
int main(){
	//freopen("t.txt","r",stdin);
	int t,n,u,v,w;
	for(scanf("%d",&t);t--;){
		for(int i=0;i<maxn;i++){
			arr[i].clear();
			dist[i]=0;
			parent[i]=-1;
			level[i]=0;
		}
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&u,&v,&w);
			arr[u].push_back({v,w});
			arr[v].push_back({u,w});
		}
		dfs();
		pre(n);
		char s[5];
		int a,b,k,u;
		while(scanf("%s",s)){
			if(s[1]=='I'){
				scanf("%d%d",&a,&b);
				u=lca(a,b);
				printf("%d\n",dist[a]+dist[b]-2*dist[u]);
			}
			else if(s[0]=='K'){
				scanf("%d%d%d",&a,&b,&k);
				u=lca(a,b);
				if(level[a]-level[u]+1>=k)
				printf("%d\n",kth(a,level[a]-k+1));
				else printf("%d\n",kth(b,2*level[u]+k-level[a]-1));
			}
			else break;
		}
		printf("\n");
	}
} 
