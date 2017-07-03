#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
const int maxn=1e5+1;
 
int arr[maxn],cp[maxn];
ll bit[maxn+5];
 
void update(int p,int val){
	for(int i=p;i<=maxn;i+=i&-i)
		bit[i]+=val;
}
 
ll sum(int p){
	ll ans=0;
	for(int i=p;i;i-=i&-i)
		ans+=bit[i];
	return ans;
}
int main(){
	//freopen("t.txt","r",stdin);
	int t,n;
	for(scanf("%d",&t);t--;){
		memset(bit,0,sizeof bit);
		scanf("%d",&n);
		ll ans=0;
		for(int i=0;i<n;i++){
			scanf("%d",&arr[i]);
			cp[i]=arr[i];
		}
		//compress
		sort(arr,arr+n);
		for(int i=0;i<n;i++){
			cp[i]=lower_bound(arr,arr+n,cp[i])-arr;
		}
		for(int i=0;i<n;i++){
			ans+=sum(cp[i]);
			update(cp[i]+1,arr[cp[i]]);
		}
		printf("%lld\n",ans);
	}
} 
