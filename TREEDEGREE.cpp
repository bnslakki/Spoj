#include "bits/stdc++.h"
using namespace std;
 
const int maxn=100005;
 
int par[maxn];
int ans[maxn];
 
int main(){
	//freopen("t.txt","r",stdin);
	int t,n,x,p,ret;
	for(scanf("%d",&t);t--;){
		ret=0;
		scanf("%d",&n);
		for(int i=0;i<n+1;i++){
			ans[i]=par[i]=0;
		}
		p=-1;
		int z=n<<1;
		for(int i=0;i<z;i++){
			scanf("%d",&x);
			if(par[x])p=par[x];
			else par[x]=p,p=x;
		}
		for(int i=2;i<=n;i++){
			ans[i]++;
			ans[par[i]]++;
		}
		for(int i=1;i<=n;i++){
			ret=max(ret,ans[i]);
		}
		printf("%d\n",ret);
	}
} 
