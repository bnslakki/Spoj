#include "bits/stdc++.h"
using namespace std;
 
const int mod=1988;
int dp[5005][5005];
 
int solve(int n,int k){
	if(!n)return 1;
	if(!k||n<0)return 0;
	if(dp[n][k]!=-1)return dp[n][k];
	return dp[n][k]=(solve(n,k-1)+solve(n-k,k))%mod;
}
int main(){
//	freopen("t.txt","r",stdin);
	memset(dp,-1,sizeof dp);
	int n,k;
	while(scanf("%d%d",&n,&k)){
		if(!n&&!k)break;
		printf("%d\n",solve(n-k,k));
	
