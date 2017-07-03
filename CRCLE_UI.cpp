#include<bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
namespace mp=boost::multiprecision;
using namespace mp;
using namespace std;
const int mod=1000000007;
int cal(int a,cpp_int b){
	long long x=1,y=a;
	while(b){
		if(b&1)x=x*y;
		if(x>=mod)x=x-(x/mod)*mod;
		y=y*y;
		if(y>=mod)y=y-(y/mod)*mod;
		b>>=1;
	}
	return x;
}
int main(){
	int t;
	cpp_int n,k;
	long long ans,a1;
	for(scanf("%d",&t);t--;){
		cin>>n>>k;
		k--;
		if(k>=mod)k%=mod;
		ans=(long long)k;
		if(n&1)ans=ans*(-1);
		a1=cal((int)k,n);
		printf("%lld\n",(a1+ans+mod)%mod);
	}
} 
