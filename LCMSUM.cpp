#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
const int N = 1000006;
ll phi[N+1],res[N+1];
 
void pre () {
	for(int i=0;i<N;i++)phi[i]=i;
	for(int i=1;i<N;i++){
		for(int j=2*i;j<N;j+=i){
			phi[j]-=phi[i];
		}
	}
	for(int i=1;i<=N;i++){
        for ( int j = i; j <= N; j += i ) {
            res[j] += ( i * phi[i] );
        }
    }
}
int main()
{
	pre();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n,num;
		scanf("%lld",&n);
		printf("%lld\n",(n*(res[n]+1))/2);
	}
} 
