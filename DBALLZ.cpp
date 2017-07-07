#include "bits/stdc++.h"
using namespace std;
 
const int maxn=1001;
typedef long long ll;
 
int val[maxn];
int wt[maxn];
int dp[1000006];
int main(){
     int t;
     for(scanf("%d",&t);t--;){
          memset(dp,0,sizeof dp);
          int n,w;
          scanf("%d%d",&w,&n);
          for(int i=0;i<n;i++){
              scanf("%d",&wt[i]);
          }
          for(int i=0;i<n;i++){
              scanf("%d",&val[i]);
          }
          for(int i=0;i<=w;i++){
              for(int j=0;j<n;j++){
                  if(wt[j]<=i)
                  dp[i]=max(dp[i],dp[i-wt[j]]+val[j]);
              }
          }
          printf("%d\n",dp[w]);
     }
} 
