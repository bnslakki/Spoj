#include "bits/stdc++.h"
using namespace std;
 
int n,m;
vector<string>arr;
bool visit[505][505];
int par[505][505];
 
bool issafe(int i,int j){
	return (i>=0)&&(j>=0)&&(i<n)&&(j<m)&&(!visit[i][j]);
}
 
void bfs(int x,int y){
	visit[x][y]=1;
	queue<pair<int,int>>q;
	q.push({x,y});
	par[x][y]=0;
	while(!q.empty()){
		pair<int,int>t=q.front();
		q.pop();		
		if(issafe(t.first+(arr[t.first][t.second]-'0'),t.second)){
			q.push({t.first+(arr[t.first][t.second]-'0'),t.second});
			visit[t.first+(arr[t.first][t.second]-'0')][t.second]=1;
			par[t.first+(arr[t.first][t.second]-'0')][t.second]=1+par[t.first][t.second];
		}
		if(issafe(t.first-(arr[t.first][t.second]-'0'),t.second)){
			q.push({t.first-(arr[t.first][t.second]-'0'),t.second});
			visit[t.first-(arr[t.first][t.second]-'0')][t.second]=1;
			par[t.first-(arr[t.first][t.second]-'0')][t.second]=1+par[t.first][t.second];
		}
		if(issafe(t.first,t.second+(arr[t.first][t.second]-'0'))){
			q.push({t.first,t.second+(arr[t.first][t.second]-'0')});
			visit[t.first][t.second+(arr[t.first][t.second]-'0')]=1;
			par[t.first][t.second+(arr[t.first][t.second]-'0')]=1+par[t.first][t.second];
		}
		if(issafe(t.first,t.second-(arr[t.first][t.second]-'0'))){
			q.push({t.first,t.second-(arr[t.first][t.second]-'0')});
			visit[t.first][t.second-(arr[t.first][t.second]-'0')]=1;
			par[t.first][t.second-(arr[t.first][t.second]-'0')]=1+par[t.first][t.second];
		}
	}
}
int main(){
	memset(par,-1,sizeof par);
	string s;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		cin>>s;
		arr.push_back(s);
	}
	bfs(0,0);
	printf("%d\n",par[n-1][m-1]);
}  
