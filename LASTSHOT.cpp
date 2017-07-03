#include "bits/stdc++.h"
using namespace std;
 
const int maxn=10001;
vector<int>arr[maxn];
int n,m,ct,visit[maxn];
 
void dfs(int s){
	visit[s]=1;
	ct++;
	for(int i=0;i<arr[s].size();i++){
		if(!visit[arr[s][i]]){
			dfs(arr[s][i]);
		}
	}
}
 
int main(){
	int a,b;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		arr[a].push_back(b);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ct=0;
		memset(visit,0,sizeof visit);
		dfs(i);
		ans=max(ct,ans);
	}
	printf("%d\n",ans);
} 
