#include<stdio.h>
 
int n;
int arr[16],cost[16];
int dp[16][1<<16];
 
int min(int a,int b){
	if(a<b)return a;
	return b;
}
int solve(int i,int pre,int mask){
	if(i==n){
		return 0;
	}
	if(dp[pre][mask]!=-1){
		return dp[pre][mask];
	}
	int ans=99999999,j;
	for(j=0;j<n;j++){
		if((mask&(1<<j))==0){
			int temp=abs((!i?arr[j]:arr[pre])-arr[j])*cost[i];
			temp+=solve(i+1,j,mask|(1<<j));
			ans=min(ans,temp);
		}
	}
	return dp[pre][mask]=ans;
}
int main(){
	int t,i,j;
	for(scanf("%d",&t);t--;){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			for(j=0;j<(1<<n);j++){
				dp[i][j]=-1;
			}
		}
		for(i=0;i<n;i++){
			scanf("%d",&arr[i]);
		}
		for(i=0;i<n;i++){
			scanf("%d",&cost[i]);
		}
		printf("%d\n",solve(0,0,0));
	}
} 
