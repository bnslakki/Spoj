#include "bits/stdc++.h"
using namespace std;
 
const int maxn=101;
 
vector<int>arr[maxn];
int parent[maxn];
bool visit[maxn];
int cap[maxn][maxn];
 
bool bfs(int s,int e){
	memset(visit,0,sizeof visit);
	queue<int>q;
	q.push(s);
	visit[s]=1;
	parent[s]=-1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<arr[u].size();i++){
			if(!visit[arr[u][i]]&&cap[u][arr[u][i]]>0){
				q.push(arr[u][i]);
				parent[arr[u][i]]=u;
				visit[arr[u][i]]=1;
			}
		}
	}
	return visit[e]==1;
}
 
int FordFulkerson(int s,int e){
	int max_flow=0;
	while(bfs(s,e)){
		int path_flow=INT_MAX;
		
		//min flow in a path
		for(int v=e;v!=s;v=parent[v]){
			int u=parent[v];
			path_flow=min(path_flow,cap[u][v]);
		}
 
		//update capacities
		for(int v=e;v!=s;v=parent[v]){
			int u=parent[v];
			cap[u][v]-=path_flow;
			cap[v][u]+=path_flow;
		}
		max_flow+=path_flow;
	}
	return max_flow;
}
 
 
int main(){
	//freopen("t.txt","r",stdin);
	int n,u,v,cp;
	char x,y;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>x>>y>>cp;
		if(x<93)u=x-65;else u=x-71;
		if(y<93)v=y-65;else v=y-71;
		arr[u].push_back(v);
		arr[v].push_back(u);
		cap[u][v]+=cp;
	}
	printf("%d\n",FordFulkerson(0,25));
} 
