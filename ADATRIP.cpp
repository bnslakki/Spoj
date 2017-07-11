#include "bits/stdc++.h"
using namespace std;
 
const int maxn = 500005;
 
vector<pair<int, int>>arr[maxn];
 
int n;
void Dials(int source, int weight){
	vector<pair<int, list<int>::iterator>>dist(n);
	for(int i = 0; i < n; i++)
		dist[i].first=INT_MAX;
	
	list<int> B[weight * n + 1];
	
	B[0].push_back(source);
	dist[source].first = 0;
	
	int i=0;
	while(1){
		while(!B[i].size() && i < weight*n)i++;
		if(i == weight*n)break;
		int u = B[i].front();
		B[i].pop_front();
		for(int j = 0; j < arr[u].size(); j++){
			int v = arr[u][j].first;
			int wt = arr[u][j].second;
			int du = dist[u].first;
            int dv = dist[v].first;
            if (dv > du + wt){
                if(dv != INT_MAX)B[dv].erase(dist[v].second);
                dist[v].first = du + wt;
                dv = dist[v].first;
                B[dv].push_front(v);
                dist[v].second = B[dv].begin();
            }
		}
	}
	int ret = 0, ct = 0;
	for(int i = 0; i < n; i++){
		if(dist[i].first != INT_MAX){
			ret = max(ret, dist[i].first);
		}
	}
	
	for(int i = 0; i < n; i++){
		if(dist[i].first == ret)ct++;
	}
	
	printf("%d %d\n",ret,ct);
}
 
int main(){
	//freopen("t.txt","r",stdin);
	int m, q, u, v, w, x, mx_wt = 0;
	scanf("%d%d%d",&n,&m,&q);
	for(int i = 0; i < m; i++){
		scanf("%d%d%d",&u,&v,&w);
		arr[u].push_back({v,w});
		arr[v].push_back({u,w});
		mx_wt = max(mx_wt, w);
	}
	while(q--){
		scanf("%d",&x);
		Dials(x, mx_wt);
	}
} 
