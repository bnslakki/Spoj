#include <stdio.h>
 
typedef long long ll;
ll n,m;
ll dp[2002];
 
ll solve(int i){
	if(!i||i==1)return 1;
	else if(i==2||i==3)return 0;
	if(dp[i]!=-1)return dp[i]%m;
	ll ans=0;
	ans+=(((i+1)*solve(i-1))%m-((i-2)*solve(i-2))%m-((i-5)*solve(i-3))%m+((i-3)*solve(i-4))%m+10*m)%m;
	return dp[i]=ans%m;
}
int main(){
	int i;
	for(i=0;i<2002;i++)dp[i]=-1;
	scanf("%lld%lld",&n,&m);
	printf("%lld\n",solve(n)%m);
} 
