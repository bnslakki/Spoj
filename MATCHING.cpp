#include "bits/stdc++.h"
using namespace std;
 
const int maxn = 100001;
 
vector<int> arr[maxn];
int match[maxn], dist[maxn];
int n, m;
 
bool bfs(){
	int u, v;
	queue<int> q;
	for(int i = 1; i <= n; i++){
		if(!match[i]){
			dist[i] = 0;
			q.push(i);
		}
		else dist[i] = INT_MAX;
	}
	dist[0] = INT_MAX;
	while(!q.empty()){
		u = q.front();
		q.pop();
		if(u){
			for(int i = 0; i < arr[u].size(); i++){
				v = arr[u][i];
				if(dist[match[v]] == INT_MAX){
					dist[match[v]] = dist[u] + 1;
					q.push(match[v]);
				}
			}
		}
	}
	return (dist[0] != INT_MAX);
}
bool dfs(int u){
	if(u){
		for(int i = 0; i < arr[u].size(); i++){
			int v = arr[u][i];
			if(dist[match[v]] == dist[u] + 1){
				if(dfs(match[v])){
					match[v] = u;
					match[u] = v;
					return 1;
				}
			}
		}
		dist[u] = INT_MAX;
		return 0;
	}
	return 1;
}
 
int HopcroftKarp(){
	int matching = 0;
    fill(match, match+n+m+1, 0);
    while(bfs()){
        for(int i = 1; i <= n; i++){
            if(!match[i] && dfs(i))
                matching++;
        }
    }
    return matching;
}
 
int main(){
    //freopen("t.txt", "r", stdin);
    int u, v, p;
    scanf("%d %d %d",&n, &m, &p);
    for(int i = 0; i < p; i++){
        scanf("%d %d",&u, &v);
 
        arr[u].push_back(v + n);
        arr[v + n].push_back(u);
    }
    printf("%d\n",HopcroftKarp());
}
