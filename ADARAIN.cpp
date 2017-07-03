#include "bits/stdc++.h"
using namespace std;

const int maxn=1e6+2;
int n,m,w;
int bit[maxn];
void update(int p,int val){
	for(int i=p;i<=maxn;i+=i&-i){
		bit[i]+=val;
	}
}

int sum(int p){
	int ans=0;
	for(int i=p;i;i-=i&-i){
		ans+=bit[i];
	}
	return ans;
}

int main(){
	//freopen("t.txt","r",stdin);
	int a,b;
	scanf("%d%d%d",&n,&m,&w);
	for(int i=0;i<n;i++){
		scanf("%d%d",&a,&b),a++,b++;
		update(a,1);
		update(b+1,-1);
	}
	for(int i=0;i<m;i++){
		scanf("%d",&a);
		printf("%d\n",sum(a+1));
	}
}
