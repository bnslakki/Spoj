#include "bits/stdc++.h"
using namespace std;
 
const int maxn=185;
const int dx[]={1,0,0,-1};
const int dy[]={0,1,-1,0};
 
int n,m;
vector<string>arr_;
int arr[maxn][maxn];
bool visit[maxn][maxn];
 
bool safe(int i,int j){
	return (i>=0)&&(j>=0)&&(i<n)&&(j<m);
}
 
bool req(int i,int j,int i_,int j_){
	if(arr[i_][j_]>arr[i][j]+1)return 1;
	return 0;
}
 
void bfs(int i,int j){
	memset(visit,0,sizeof visit);
	visit[i][j]=1;
	queue<pair<int,int>>q;
	q.push({i,j});
	while(!q.empty()){
		pair<int,int>t=q.front();
		q.pop();
		for(int k=0;k<4;k++){
			if(safe(t.first+dx[k],t.second+dy[k])&&req(t.first,t.second,t.first+dx[k],t.second+dy[k])){
				arr[t.first+dx[k]][t.second+dy[k]]=1+arr[t.first][t.second];
				visit[t.first+dx[k]][t.second+dy[k]]=1;
				q.push({t.first+dx[k],t.second+dy[k]});
			}
		}
	}
}
int main(){
	//read("t.txt");
	int t;
	string s;
	for(scanf("%d",&t);t--;){
		memset(arr,0,sizeof arr);
		arr_.clear();
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			cin>>s;
			arr_.push_back(s);
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(arr_[i][j]=='0')arr[i][j]=INT_MAX;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(!arr[i][j]){
					bfs(i,j);
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				printf("%d ",arr[i][j]);
			}
			printf("\n");
		}
	}
} 
