#include "bits/stdc++.h"
using namespace std;
 
int n,m,k;
int cost1[22],cost[22][22],rate[20][20],dp[1001][20][2];
 
int solve(int COST,int i,int flag){
	if(i==n){
		return 0;
	}
	if(dp[COST][i][flag]!=-1){
		return dp[COST][i][flag];
	}
	int ans=0;
	int z1=solve(COST,i+1,0);
	if(flag==0&&cost1[i]<=COST){
		COST-=cost1[i];
		for(int j=0;j<m;j++){
			if(COST>=cost[i][j])
			ans=max(ans,solve(COST-cost[i][j],i,1)+rate[i][j]);
		}
		COST+=cost1[i];
	}
	else if(flag){
		for(int j=0;j<m;j++){
			if(COST>=cost[i][j])
			ans=max(ans,solve(COST-cost[i][j],i,1)+rate[i][j]);
		}
	}	
	return dp[COST][i][flag]=max(ans,z1);
}
 
int main(){
//	read("t.txt");
	int t;
	for(scanf("%d",&t);t--;){
		memset(dp,-1,sizeof dp);
		scanf("%d%d%d",&n,&m,&k);
		for(int i=0;i<n;i++){
			scanf("%d",&cost1[i]);
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%d",&cost[i][j]);
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%d",&rate[i][j]);
			}
		}
		printf("%d\n",solve(k,0,0));
	}
} 
