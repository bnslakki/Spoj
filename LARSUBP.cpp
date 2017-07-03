#include "bits/stdc++.h"
using namespace std;
 
string s;
const int mod=1e9+7;
map<pair<int,int>,int>mp;
int solve(int i,int pre=-1){
	if(i==s.length()){
		if(pre!=-1)return 1;
		return 0;
	}
	if(mp.find({i,pre})!=mp.end())return mp[{i,pre}];
	int ans=0;
	if((s[i]-'0')>pre){
		ans=(ans+solve(i+1,s[i]-'0')+solve(i+1,pre))%mod;
	}
	else ans=(ans+solve(i+1,pre))%mod;
	return mp[{i,pre}]=ans;
}
 
int main(){
	//freopen("t.txt","r",stdin);
	int t,tc=1;
	for(scanf("%d",&t);t--;){
		mp.clear();
		cin>>s;
		printf("Case %d: %d\n",tc++,solve(0));
	}
} 
