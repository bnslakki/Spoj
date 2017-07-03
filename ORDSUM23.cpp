#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
 
const int mod=1000000007;
const int maxn=1000001;
 
ll arr[maxn],dp[maxn],temp;
 
ll solve(int n){
	if(n<0)return 0;
	if(!n)return 1;
	if(dp[n]!=-1)return dp[n];
	temp=solve(n-2)+solve(n-3);
	//if(temp>=mod)temp%=mod;
	if(temp>=mod)temp=temp-mod*(temp/mod);
	return dp[n]=temp;
}
 
void pre(){
	memset(dp,-1,sizeof dp);
	arr[1]=0;
	for(int i=2;i<maxn;i++){
		arr[i]=solve(i);
	}
}
 
int main(){
//	read("t.txt");
	pre();
	int t;
	for(scanf("%d",&t);t--;){
		int n;
		scanf("%d",&n),printf("%lld\n",arr[n]);
	}
} 
