#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
const int mod=1000000007;
 
int arr[26];
ll dp[100001];
int main(){
	int t;
	for(scanf("%d",&t);t--;){
		memset(arr,-1,sizeof arr);
		string s;
		cin>>s;
		dp[0]=1;
		for(int i=1;i<=s.length();i++){
			dp[i]=dp[i-1]<<1;
			if(dp[i]>=mod)dp[i]%=mod;
			if(arr[s[i-1]-'A']!=-1){
				dp[i]-=dp[arr[s[i-1]-'A']];
				dp[i]=(dp[i]+mod)%mod;
			}
			arr[s[i-1]-'A']=i-1;
		}
		printf("%lld\n",dp[s.length()]);
	}
} 
