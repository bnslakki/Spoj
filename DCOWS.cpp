#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
 
const int maxn=5005;
 
int n,m;
ll bull[maxn],cow[maxn];
ll dp[maxn][maxn];
 
ll solve(int i,int j){
	if(i==-1){
		return 0;
	}
	if(i>j)return 12345678987456;
	if(dp[i][j]!=-1)return dp[i][j];
	return dp[i][j]=min(abs(bull[i]-cow[j])+solve(i-1,j-1),solve(i,j-1));
}
 
int main(){
//	read("t.txt");
	memset(dp,-1,sizeof dp);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%lld",&bull[i]);
	}
	for(int i=0;i<m;i++){
		scanf("%lld",&cow[i]);
	}
	sort(bull,bull+n);
	sort(cow,cow+m);
	printf("%lld\n",solve(n-1,m-1));
} 
