#include "bits/stdc++.h"
using namespace std;
 
string ori;
int iter;
 
int dp[10001][101];
 
bool solve(string s,int i){
	if(i==iter){
		if(s>ori)return 1;
		return 0;
	}
	int z=stoi(s);
	if(dp[z][i]!=-1)return dp[z][i];
	bool ans=0;
	if(i&1){
		ans=1;
	}
	for(int k=0;k<4;k++){
		string tm=s;
		if(tm[k]=='9')tm[k]='0';
			else tm[k]++;
		if(i&1){
			ans&=solve(tm,i+1);
		}
		else {
			ans|=solve(tm,i+1);
		}
	}
	return dp[z][i]=ans;
}
 
int main(){
	//read("t.txt");
	int t;
	string s;
	for(scanf("%d",&t);t--;){
		memset(dp,-1,sizeof dp);
		cin>>s;
		ori=s;
		scanf("%d",&iter);
		if(solve(s,0))printf("Ada\n");
		else printf("Vinit\n");
	}
}  
