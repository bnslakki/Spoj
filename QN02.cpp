#include "bits/stdc++.h"
using namespace std;
 
const int maxn=1e5+5;
int par[maxn];
 
int root(int v){return par[v]<0?v:(par[v]=root(par[v]));}
void merge(int x,int y){
    if((x=root(x))==(y=root(y)))return ;
	if(par[y] < par[x])swap(x,y);
	par[x]+=par[y];
	par[y]=x;
}
int main(){
	int n,m,x,y,q;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n+1;i++)par[i]=-1;
	for(int i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		merge(x,y);
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&x,&y);
		if(root(x)==root(y))printf("YES\n");
		else printf("NO\n");
	}
} 
