#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
const int maxn=1025;
int n;
int bit[maxn+5][maxn+5];
 
void update(int x,int y,int val) {
	for(int i=x;i<=n+5;i=i|(i+1))
		for(int j=y;j<=n+5;j=j|(j+1))
			bit[i][j]+=val;
}
 
ll sum(int x,int y) {
	ll res=0;
	for(int i=x;i>0;i=(i&(i+1))-1)
		for(int j=y;j>0;j=(j&(j+1))-1)
			res+=bit[i][j];
	return res;
}
 
int main(){
	//freopen("t.txt","r",stdin);
	int t;
	for(scanf("%d",&t);t--;){
		memset(bit,0,sizeof bit);
		scanf("%d",&n);
		char s[10];
		int x1,y1,x2,y2,num;
		while(1){
			scanf("%s",s);
			if(s[1]=='N')break;
			if(s[1]=='E'){
				scanf("%d%d%d",&x1,&y1,&num);
				x1++,y1++;
				update(x1,y1,num-sum(x1,y1)-sum(x1-1,y1-1)+sum(x1,y1-1)+sum(x1-1,y1));
			}
			else{
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				x1++,y1++,x2++,y2++;
				printf("%lld\n",sum(x2,y2)-sum(x2,y1-1)-sum(x1-1,y2)+sum(x1-1,y1-1));
			}
		}
		printf("\n");
	}
} 
