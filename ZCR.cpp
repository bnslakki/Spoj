#include "bits/stdc++.h"
using namespace std;
 
const int maxn=1001;
int n,k;
double arr[maxn];
double dp[maxn][maxn];
 
double solve(int i,int h){
	if(i==n){
		if(h==k)return 1.0;
		return 0.0;
	}
	if(dp[i][h]!=-1.0){
		return dp[i][h];
	}
	double ans=0.0;
	ans+=(solve(i+1,h+1)*arr[i]+solve(i+1,h)*(1.0-arr[i]));
	return dp[i][h]=ans;
}
int main(){
	//read("t.txt");
	int t;
	for(scanf("%d",&t);t--;){
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				dp[i][j]=-1.0;
			}
		}
		for(int i=0;i<n;i++){
			scanf("%lf",&arr[i]);
		}
		printf("%.10lf\n",solve(0,0));
	}
} 
