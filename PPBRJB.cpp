#include "bits/stdc++.h"
using namespace std;
 
int dp[44];
int solve(int i){
	if(i==0)return 1;
	if(i<0)return 0;
	if(dp[i]!=-1)return dp[i];
	return dp[i]=solve(i-1)+solve(i-4);
}
bool isprime(int num){
	for(int i=2;i<=sqrt(num);i++){
		if(num%i==0)return 0;
	}
	return 1;
}
int main(){
	int t,n;
	memset(dp,-1,sizeof dp);
	for(scanf("%d",&t);t--;){
		scanf("%d",&n);
		int ans=solve(n);
		int ret=0;
		for(int i=2;i<=ans;i++){
			if(isprime(i))ret++;
		}
		printf("%d\n",ret);
	}
} 
