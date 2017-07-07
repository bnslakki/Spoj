#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
const int maxn=34;
 
ll arr[maxn];
ll p1[1<<(maxn>>1)],p2[1<<(maxn>>1)];
 
void sub(ll a[],int n,int s){
    for(int i=0;i<(1<<n);i++){
        ll sum=0;
        for(int j=0;j<n;j++)
            if(i&(1<<j))
                sum+=arr[j+s];
        a[i]=sum;
    }
}
 
int main(){
	int n;
	ll a,b,ans=0;
	scanf("%d%lld%lld",&n,&a,&b);
	for(int i=0;i<n;i++){
		scanf("%lld",&arr[i]);
	}
	sub(p1,n>>1,0);
	sub(p2,n-(n>>1),n>>1);
	sort(p2,p2+(1<<(n-(n>>1))));
	
	for(int i=0;i<(1<<(n>>1));i++){
		int l=lower_bound(p2,p2+(1<<(n-(n>>1))),a-p1[i])-p2;
		int h=upper_bound(p2,p2+(1<<(n-(n>>1))),b-p1[i])-p2;
		ans+=(h-l);
	}
	printf("%lld\n",ans);
} 
