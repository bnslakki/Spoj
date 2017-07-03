#include "bits/stdc++.h"
using namespace std;
 
const int maxn=202;
int n;
int arr[maxn];
int dp[maxn][maxn][maxn];
 
int solve(int i,int white,int black){
	if(i==n)return 0;
	if(dp[i][white][black]!=-1){
		return dp[i][white][black];
	}
	int ans2=0,ans3=0;
	if(white==n||arr[i]>arr[white])ans2=1+solve(i+1,i,black);
	if(black==n||arr[i]<arr[black])ans3=1+solve(i+1,white,i);
	return dp[i][white][black]=max(solve(i+1,white,black),max(ans2,ans3));
}
 
int main(){
	//freopen("t.txt","r",stdin);
	while(scanf("%d",&n)){
		if(n==-1)break;
		memset(dp,-1,sizeof dp);
		for(int i=0;i<n;i++)scanf("%d",&arr[i]);
		printf("%d\n",n-solve(0,n,n));
	}
} 
