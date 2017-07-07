#include "bits/stdc++.h"
using namespace std;
 
string s1,s2;
int n;
int dp[101][101][101];
 
int solve(int i,int j,int k){
	
	if(k==n){
		return 0;
	}
	if(i==s1.length())return -9999999;
	if(j==s2.length())return -9999999;
	if(dp[i][j][k]!=-1){
		
		return dp[i][j][k];
	}
	int ans=0;
	if(s1[i]==s2[j]){
		int z=s1[i];
		ans+=max(solve(i+1,j+1,k+1)+z,max(solve(i+1,j,k),solve(i,j+1,k)));
	}
	else{
		ans+=max(solve(i+1,j,k),solve(i,j+1,k));
	}
	return dp[i][j][k]=ans;
}
int main(){
//	read("t.txt");
	int t;
	for(scanf("%d",&t);t--;){
		memset(dp,-1,sizeof dp);
		cin>>s1>>s2;
		scanf("%d",&n);
		int z=solve(0,0,0);
		if(z<0)z=0;
		printf("%d\n",z);
	}
} 
