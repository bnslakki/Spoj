#include "bits/stdc++.h"
using namespace std;
 
string s;
const int maxn=5005;
int dp[1005][maxn];
 
int solve(int i,int sum){
	if(i==s.size()){
		if(sum)return 1e9;
		return 0;
	}
	if(dp[i][sum]!=-1)return dp[i][sum];
	int ret=1e9;
	int num=0;
	for(int k=i;k<s.size();k++){
		num=num*10+(s[k]-'0');
		if(num>sum)break;
		ret=min(ret,1+solve(k+1,sum-num));
	}
	return dp[i][sum]=ret;
}
int main(){
	memset(dp,-1,sizeof dp);
	string s1;
	cin>>s1;
	int i;
	int c=0;
	for(i=0;i<s1.length();i++){
		if(s1[i]=='=')break;
		if(s1[i]!='0'){
			s.push_back(s1[i]);
			c=0;
		}
		else if(s1[i]=='0'&&c<=3){
			s.push_back(s1[i]);
			++c;
		}
	}
	int sum=0;
	for(int j=i+1;j<s1.length();j++){
		sum=sum*10+(s1[j]-'0');
	}
	printf("%d\n",solve(0,sum)-1);
} 
