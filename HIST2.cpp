#include "bits/stdc++.h"
using namespace std;
 
int n;
int arr[16];
int nop[16][1<<16];
int dp[16][1<<16];
 
int solve(int cur,int mask){
	if(mask==(1<<n)-1){
		nop[cur][mask]=1;
		return arr[cur];
	}
	if(dp[cur][mask]!=-1)return dp[cur][mask];
	int ret=0;
	for(int i=0;i<n;i++){
		if((mask&(1<<i))==0){
			int ans=solve(i,mask|(1<<i))+abs(arr[cur]-arr[i]);
			if(ans>ret){
				ret=ans;
				nop[cur][mask]=0;
			}
			if(ans==ret)
			nop[cur][mask]+=nop[i][mask|(1<<i)];
		}
	}
	return dp[cur][mask]=ret;
}
int main(){
	while(scanf("%d",&n)){
		if(!n)break;
		memset(dp,-1,sizeof dp);
		memset(nop,0,sizeof nop);
		for(int i=0;i<n;i++)scanf("%d",&arr[i]);
		int temp=0,ans=0,ans2=0;
		for(int i=0;i<n;i++){
			temp=solve(i,0|(1<<i))+2*n+arr[i];
			if(temp>ans){
				ans=temp;
				ans2=nop[i][1<<i];
			}
			else if(ans==temp){
				ans2+=nop[i][1<<i];
			}
		}
		printf("%d %d\n",ans,ans2);
	}
} 
