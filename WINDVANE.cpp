#include "bits/stdc++.h"
using namespace std;
 
const int maxn=1001;
map<int,char>mp;
map<char,int>mp1;
 
int n,m;
int bit[maxn][maxn];
 
void update(int x,int y,int val) {
	for(int i=x;i<=n;i=i|(i+1))
		for(int j=y;j<=m;j=j|(j+1))
			bit[i][j]+=val;
}
 
int sum(int x,int y) {
	int res=0;
	for(int i=x;i>0;i =(i&(i+1))-1)
		for(int j=y;j>0;j=(j&(j+1))-1)
			res+=bit[i][j];
	return res;
}
 
int main(){
	mp[0]='N',mp[1]='E',mp[2]='S',mp[3]='W';
	mp1['N']=0,mp1['E']=1,mp1['S']=2,mp1['W']=3;
	char c;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("\n%c",&c);
			update(i,j,mp1[c]);
			update(i+1,j,-mp1[c]);
            update(i,j+1,-mp1[c]);
            update(i+1,j+1,mp1[c]);
		}
	}
	int q;
	int x1,y1,x2,y2,ty;
	for(scanf("%d",&q);q--;){
		scanf("\n%c",&c);
		if(c=='C'){
			scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&ty);
			if(ty)ty=-1;
			else ty=1;
			update(x1,y1,ty);
			update(x2+1,y1,-ty);
			update(x1,y2+1,-ty);
			update(x2+1,y2+1,ty);
		}
		else{
			scanf("%d%d",&x1,&y1);
			int s=sum(x1,y1)%4;
			if(s<0)s+=4;
			printf("%c\n",mp[s]);
		}
	}
} 
