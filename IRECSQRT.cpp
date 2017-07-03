#include<bits/stdc++.h>
 
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
using namespace mp;
using namespace std;
 
cpp_int power(cpp_int a,cpp_int b,cpp_int c){
	cpp_int x=1,y=a;
	while(b){
		if(b&1){
			x=x*y;
			if(x>=100000*c)x%=c;
		}
		y=y*y;
		if(y>=100000*c)y%=c;
		b>>=1;
	}
	return x%c;
}
int main(){
	int t;
	for (scanf("%d", &t); t--;){
		cpp_int n,a1,a2,a3=1,ans,MOD;
		cin >> n >> MOD;
		if(n==0){
			printf("1\n");
			continue;
		}
		MOD = 3 * MOD;
		a1=power(2,2*n-1,MOD);
		a2=power(2,n-1,MOD);
		a2=3*a2;
		ans=(a1+a2+a3)%MOD;
		ans=ans/3;
		cout<<ans<<'\n';
	}
} 
