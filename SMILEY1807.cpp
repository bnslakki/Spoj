#include "bits/stdc++.h"
using namespace std;
 
string s;
 
int dp[1000002][5];
 
int solve(int i,int pre=2){
	if(i==s.length()){
		if(pre==7)
		return 0;
		return INT_MIN;
	}
	if(dp[i][pre]!=-1){
		return dp[i][pre];
	}
	int ans=0,ret=0;
	if(pre==2){
		if(s[i]=='1'){
			ans=1+solve(i+1,1);
		}
		else ans=solve(i+1,pre);
	}
	else{
		if(pre==1){
			if(s[i]=='8'||s[i]=='0'||s[i]=='7'){
				ans=max(solve(i+1,pre),1+solve(i+1,s[i]-'0'));
			}
			else if(s[i]=='1')ans=1+solve(i+1,pre);
			else ans=solve(i+1,pre);
		}
		else if(pre==8){
			if(s[i]=='0'||s[i]=='7'){
				ans=max(solve(i+1,pre),1+solve(i+1,s[i]-'0'));
			}
			else if(s[i]=='8')ans=1+solve(i+1,pre);
			else ans=solve(i+1,pre);
		}
		else if(pre==0){
			if(s[i]=='7'){
				ans=max(solve(i+1,pre),1+solve(i+1,s[i]-'0'));
			}
			else if(s[i]=='0')ans=1+solve(i+1,pre);
			else ans=solve(i+1,pre);
		}
		else if(pre==7){
			if(s[i]=='7')
			ans=1+solve(i+1,pre);
			else ans=solve(i+1,pre);
		}
	}
	//printf("%d ",ans);
	return dp[i][pre]=max(ret,ans);
}
int main(){
	memset(dp,-1,sizeof dp);
	cin>>s;
	printf("%d\n",solve(0));
} 
