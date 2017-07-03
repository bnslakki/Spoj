#include "bits/stdc++.h"
using namespace std;
 
int main(){
	int t;
	for(scanf("%d",&t);t--;){
		int n,k,s,d,m,f=0,c=0,ans;
		scanf("%d%d",&n,&k);
		int in[n];
		memset(in,0,sizeof in);
		for(int i=0;i<k;i++){
			scanf("%d%d%d",&s,&d,&m);
			in[s]+=m,in[d]+=m;
		}
		for(int i=1;i<=n;i++){
			if(in[i]&1){
				c++;
				if(!f)ans=i,f=1;
			}
		}
		if(c<=2)printf("YES %d\n",ans);
		else printf("NO\n");
	}
} 
