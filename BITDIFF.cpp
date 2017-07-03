#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
 
const int mod=10000007;
const int maxn=1e4+1;
 
ll arr[maxn];
 
int main(){
	int t,n,tc=1;
	for(scanf("%d",&t);t--;){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%lld",&arr[i]);
		}
		ll ret=0,one;
		for(int i=0;i<32;i++){
			one=0;
			for(int j=0;j<n;j++){
				if(arr[j]&(1<<i))one++;
			}
			ret+=one*(n-one);
			if(ret>=mod)ret%=mod;
		}
		ret<<=1;
		if(ret>=mod)ret%=mod;
		printf("Case %d: %lld\n",tc++,ret);
	}
	return 0;
} 
