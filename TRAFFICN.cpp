#include "bits/stdc++.h"
using namespace std;
 
const int maxn = 10001;
 
vector<pair<int, int>>arr[maxn], arr1[maxn];
int dist[maxn], dist1[maxn];
int n,m,k,s,t;
 
int dijkstra(int source, int vertex, vector<pair<int, int>>g[], int dis[]){
	
	int u, v, w;
	// Initialize Single Source
	for(int i = 1; i <= vertex; i++) dis[i] = 200000000;
	dis[source] = 0;
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
	q.push({source,0});
	
	while (!q.empty()){
		u = q.top().first;
		q.pop();
		for (int i = 0; i < g[u].size(); i++){
			v = g[u][i].first;
			w = g[u][i].second;
 
			// Relax
			if(dis[v] > w + dis[u]){
				dis[v] = w + dis[u];
				q.push({v, dis[v]});
			}
		}
	}
}
 
int main(){
	//freopen("t.txt","r",stdin);
	int tc, u, v, w, ans;
	for(scanf("%d", &tc); tc--;){
		scanf("%d %d %d %d %d", &n, &m, &k, &s, &t);
		for(int i = 0; i < n + 1; i++){
			arr[i].clear(), arr1[i].clear();
		}
		for(int i = 0; i <m; i++){
			scanf("%d %d %d", &u, &v, &w);
			arr[u].push_back({v, w});
			arr1[v].push_back({u, w});
		}
		dijkstra(s, n, arr, dist);
		dijkstra(t, n, arr1, dist1);
		ans = dist[t];
		for(int i = 0; i < k; i++){
			scanf("%d %d %d",&u, &v, &w);
			ans = min(ans, w + min(dist[u] + dist1[v], dist[v] + dist1[u]));
		}
		if(ans == 200000000)printf("-1\n");
		else printf("%d\n",ans);
	}
} 
