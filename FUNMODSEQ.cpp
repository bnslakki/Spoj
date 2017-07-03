#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
 
int gcd(int a,int b,int &x,int &y){
	if(!a){
		x=0,y=1;
		return b;
	}
	int x1,y1;
	int d=gcd(b%a,a,x1,y1);
	x=y1-(b/a)*x1;
	y=x1;
	return d;
}
int main(){
	int t,a,p,g;
	ll n;
	for(scanf("%d",&t);t--;){
		int x,y;
		scanf("%d%d%lld",&a,&p,&n);
		g=gcd(a,p,x,y);
		ll x_=(x+p)%p;
		ll a_=a;
		if(g==1){
			printf("%lld\n",(n-(n>>1))*a_+(n>>1)*x_);
		}
		else printf("-1\n");
	}
} 
