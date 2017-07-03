#include "bits/stdc++.h"
using namespace std;
 
const int maxn=101;
int k,b;
int dist[maxn][maxn];
int start[15],End[15],dp[1<<15][100];
 
int solve(int mask,int pre){
	if(mask==(1<<k)-1)return dist[pre][b];
	if(dp[mask][pre]!=-1)return dp[mask][pre];
	int ans=INT_MAX;
	for(int i=0;i<k;i++){
		if(!(mask&(1<<i))){
			ans=min(ans,solve(mask|(1<<i),End[i])+dist[pre][start[i]]+dist[start[i]][End[i]]);
		}
	}
	return dp[mask][pre]=ans;
}
int main(){
	int t,u,v,w,z,n,m;
	int s,e,nop;
	for(scanf("%d",&t);t--;){
		k=0;
		memset(dp,-1,sizeof dp);
		scanf("%d%d%d",&n,&m,&b);b--;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				dist[i][j]=(i==j)?0:99999999;
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&u,&v,&w);u--,v--;
			dist[u][v]=w;
			dist[v][u]=w;
		}
		// floyd warshall algo
		for(int k=0;k<n;k++)
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
		scanf("%d",&z);
		for(int i=0;i<z;i++){
			scanf("%d%d%d",&s,&e,&nop);s--,e--;
			for(int j=0;j<nop;j++){
				start[k]=s;
				End[k]=e;
				k++;
			}
		}
		printf("%d\n",solve(0,b));
	}
} 
