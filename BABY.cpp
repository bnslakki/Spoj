#include "bits/stdc++.h"
using namespace std;
 
const int maxn=18;
int arr1[maxn],arr2[maxn],dp[1<<maxn];
int n;
 
int fun(int st,int mask){
	if(st==n){
		return 0;
	}
	if(dp[mask]!=-1)return dp[mask];
	int ans=INT_MAX;
	for(int i=0;i<n;i++){
		if((mask&(1<<i))==0){
			int dis=abs(st-i)+abs(arr1[st]-arr2[i]);
			dis+=fun(st+1,mask|(1<<i));
			ans=min(ans,dis);
		}
	}
	return dp[mask]=ans;
}
 
int main(){
	while(scanf("%d",&n))
	{
		if(!n)break;
		memset(dp,-1,sizeof dp);
		for(int i=0;i<n;i++){
			scanf("%d",&arr1[i]);
		}
		for(int i=0;i<n;i++){
			scanf("%d",&arr2[i]);
		}
		printf("%d\n",fun(0,0));
	}
} 
