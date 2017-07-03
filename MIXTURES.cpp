#include "bits/stdc++.h"
using namespace std;
 
int arr[101];
int n;
 
int sum(int i,int j){
	int ret=0;
	for(int k=i;k<=j;k++){
		ret+=arr[k];
	}
	return ret%100;
}
int dp[101][101];
int solve(int i,int j){
	if(i==j)return 0;
	int ans=INT_MAX;
	if(dp[i][j]!=-1)return dp[i][j];
	for(int k=i;k<j;k++){
		int ct=solve(i,k)+solve(k+1,j)+sum(i,k)*sum(k+1,j);
		//printf("%d\n",ct);
		ans=min(ans,ct);
	}
	return dp[i][j]=ans;
}
 
int main(){
	while(scanf("%d",&n)!=EOF){
		memset(dp,-1,sizeof dp);
		for(int i=0;i<n;i++){
			scanf("%d",&arr[i]);
		}
		printf("%d\n",solve(0,n-1));
	}
	
} 
