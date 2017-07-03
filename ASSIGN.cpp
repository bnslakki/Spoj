#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
int arr[22][22];
ll dp[1<<22];
int n;

ll fun(int mask){

  int k= n-__builtin_popcount(mask); 
  if(dp[mask]!=-1)return dp[mask];
  ll ans=0;
  for(int i=0;i<n;i++){
    if(arr[k][i]&&((mask>>(n-1-i))&1)){
      int temp=(mask&~(1<<(n-1-i)));
      if(k<n-1)
        ans+=fun(temp);
      else 
        ans++;
    }
  }
  return dp[mask]=ans;
}

void clear(int sz){
  for(int i=0;i<sz+2;i++){
    dp[i]=-1;
  }
}
int main(){
  int t;
  for(scanf("%d",&t);t--;){
    scanf("%d",&n);
    clear(1<<n);
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        scanf("%d",&arr[i][j]);
      }
    }
    printf("%lld\n",fun((1<<n)-1));
  }

}  
