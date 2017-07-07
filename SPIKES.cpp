#include "bits/stdc++.h"
using namespace std;
 
const int maxn=44;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
 
int n,m,s,s_c,ans;
bool visit[maxn][maxn];
vector<string>arr;
pair<int,int>path[maxn*maxn+maxn];
 
bool issafe(int i,int j){
	return (i>=0)&&(j>=0)&&(i<n)&&(j<m)&&(!visit[i][j]);
}
 
bool pos(int i,int j,int& sp){	
	if(arr[i][j]=='#')return 0;
	if(arr[i][j]=='.'||arr[i][j]=='x')return 1;
	if(arr[i][j]=='s'&&sp>0){
		sp--;
		return 1;
	}
	return 0;
}
 
void dfs(int i,int j,int &in,int& s1){
	visit[i][j]=1;
	path[in++]={i,j};
	if(arr[i][j]=='x'){
	//	printf("spike is %d\n",s1);
		if(2*(s_c-s1)<=s_c){
			ans=1;
		}
//		for(int k=0;k<in;k++){
//			printf("%d %d\n",path[k].first,path[k].second);
//		}
//		printf("\n");
	}
	else{
		for(int k=0;k<4;k++){
			int temp=s1;
			if(issafe(i+dx[k],j+dy[k])&&pos(i+dx[k],j+dy[k],temp)){
				dfs(i+dx[k],j+dy[k],in,temp);
			}
		}
	}
	in--;
	visit[i][j]=0;
}
int main(){
//	read("t.txt");
	scanf("%d%d%d",&n,&m,&s);
	s_c=s;
	string st;
	for(int i=0;i<n;i++){
		cin>>st;
		arr.push_back(st);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]=='@'){
				int z=0;
				memset(visit,0,sizeof visit);
				dfs(i,j,z,s);
				if(ans)goto bnsl;
			}
		}
	}
	printf("IMPOSSIBLE\n");
	bnsl:
		if(ans)
		printf("SUCCESS\n");
}
 
