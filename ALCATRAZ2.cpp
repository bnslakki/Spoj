#include "bits/stdc++.h"
using namespace std;
 
int arr[10],pos[10];
 
int solve(int i,int mask){
	if(i==(1<<3)+1)return 0;
	int ret=0;
	for(int i=1;i<=1<<3;i++){
		if((mask&(1<<i))||(pos[i]&mask))continue;
		ret=max(ret,arr[i]+solve(i+1,mask|(1<<i)));
	}
	return ret;
}
int main(){
	//freopen("t.txt","r",stdin);
	int p,x,y;
	for(int i=1;i<=8;i++)scanf("%d",&arr[i]);
	scanf("%d",&p);
	for(int i=0;i<p;i++){
		scanf("%d%d",&x,&y);
		pos[x]|=1<<y;
		pos[y]|=1<<x;
	}
	printf("%d\n",solve(0,0));
} 
