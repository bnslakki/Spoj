#include <stdio.h>
 
int n;
double dp[536][1890];
 
int min(int a,int b){
	if(a<b)return a;
	return b;
}
double solve(int i,int k){
	if(!k&&i!=n)return 0;
	if(i==n){
		if(!k)return 1;
		return 0;
	}
	if(dp[i][k]!=1){
		return dp[i][k];
	}
	int j;
	double ans=0;
	for(j=1;j<=min(6,k);j++){
		ans+=solve(i+1,k-j);
	}
	return dp[i][k]=ans/6.0;
}
 
int main(){
	int t,k,i,j;
	for(scanf("%d",&t);t--;){
		for(i=0;i<536;i++){
			for(j=0;j<1890;j++){
				dp[i][j]=1;
			}
		}
		scanf("%d%d",&n,&k);
		if(n>=535||k>1880){
			printf("0\n");
			continue;
		}
		double ans=100*solve(0,k);
		printf("%d\n",(int)ans);
	}
} 
