#include "bits/stdc++.h"
using namespace std;
 
const int maxn=22;
const int dx[4]={0,1,-1,0};
const int dy[4]={1,0,0,-1};
 
int k=0;
int n,m;
string in[maxn];
pair<int,int>arr[maxn];
int dist[12][12];
int visit[maxn][maxn];
int dp[1<<12][12];
 
int solve(int mask,int pre){
	if(mask==(1<<k)-1)return 0;
	if(dp[mask][pre]!=-1)return dp[mask][pre];
	int ans=INT_MAX;
	for(int i=0;i<k;i++){
		if(!(mask&(1<<i))){
			ans=min(ans,solve(mask|(1<<i),i)+dist[pre][i]);
		}
	}
	return dp[mask][pre]=ans;
}
 
bool issafe(int i,int j){
	return (i>=0)&&(j>=0)&&(i<n)&&(j<m)&&!visit[i][j]&&in[i][j]!='x';
}
 
int bfs(int i){
	memset(visit,0,sizeof visit);
	queue<pair<int,pair<int,int>>>q;
	q.push({0,{arr[i].first,arr[i].second}});
	int ct=0;
	while(!q.empty()){
		pair<int,pair<int,int>>p=q.front();
		q.pop();
		if(visit[p.second.first][p.second.second])continue;
		visit[p.second.first][p.second.second]=1;
		if(in[p.second.first][p.second.second]=='o'){
			dist[i][0]=p.first;
			ct++;
		}
		if(in[p.second.first][p.second.second]>='0'&&in[p.second.first][p.second.second]<='9'){
			dist[i][in[p.second.first][p.second.second]-'0'+1]=p.first;
			ct++;
		}
		for(int k=0;k<4;k++){
			if(issafe(p.second.first+dx[k],p.second.second+dy[k])){
				q.push({p.first+1,{p.second.first+dx[k],p.second.second+dy[k]}});
			}
		}
	}
	//printf("%d\n",ct);
	return ct==k;
}
 
int main(){
	//freopen("t.txt","r",stdin);
	bool f=0;
	while(scanf("%d%d",&m,&n)){
		if(!n&&!m)break;
		memset(dp,-1,sizeof dp);
		k=1,f=0;
		for(int i=0;i<n;i++){
			cin>>in[i];
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(in[i][j]=='o'){
					arr[0]={i,j};
				}
				if(in[i][j]=='*'){
					in[i][j]='0'+k-1;
					arr[k++]={i,j};
				}
			}
		}
		//printf("%d\n",k);
		for(int i=0;i<k;i++){
			if(!bfs(i)){
				f=1;
				break;
			}
		}
		if(f)printf("-1\n");
		else{
			printf("%d\n",solve(0,0));
		}
	}
} 
