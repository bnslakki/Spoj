#include<stdio.h>
 
int n,m;
char arr[202][202];
int dp[202][202][2];
 
int max(int i,int j){
	if(i>j)return i;
	return j;
}
 
int solve(int i,int j,int f){
	
	if(i>=m||j>=n||i<0||j<0)
		return 0;
	if(arr[i][j]=='#')
		return 0;
	if(dp[i][j][f]!=-1){
		return dp[i][j][f];
	}
	int ans=0;
	if(arr[i][j]=='T')ans=1;
	
	ans+=max(solve(i+1,j,1-f),solve(i,j+(f==0?1:-1),f));
	
	return dp[i][j][f]=ans;
}
int main(){
	//read("t.txt");
	int t,i,j,k;
	for(scanf("%d",&t);t--;){
		for(i=0;i<202;i++){
			for(j=0;j<202;j++){
				for(k=0;k<2;k++){
					dp[i][j][k]=-1;
				}	
			}
		}
		scanf("%d%d",&m,&n);
		for(int i=0;i<m;i++){
			scanf("%s",arr[i]);
		}
		printf("%d\n",solve(0,0,0));
	}
} 
