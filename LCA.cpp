#include<bits/stdc++.h>
using namespace std;
 
const int MAXN = 1005;
 
vector<int> v[MAXN];
vector<int> first_occur[MAXN];
vector<int> euler,lev;
void dfs(int s,int level,int p=-1){
	euler.push_back(s);
	//printf("%d ",s);
	lev.push_back(level);
	if(!first_occur[s].size())first_occur[s].push_back(euler.size());
	for(int i=0;i<v[s].size();i++){
		if(p-i){
			dfs(v[s][i],level+1);
			if(!first_occur[s].size())first_occur[s].push_back(euler.size());
			euler.push_back(s);
			lev.push_back(level);
			//printf("%d ",s);
		}
	}
}
int len;
vector<int> b;
void sqrt_decompose(){
	len = (int)ceil(sqrt(lev.size()));
	b.resize(len+2);
	int mn = INT_MAX, flip = 0, index;
	for(int i=0;i<lev.size();i++){
		if(i/len==flip){
			if(lev[i]<mn){
				mn=lev[i];
				index=i;
			}
		}
		else{
			b[flip] = index;
			mn = INT_MAX;
			flip++;
		}
	}
	b[flip]=mn;
}
int query(int i,int j){
	int startblock = i/len;
	int endblock = j/len;
	int mn = INT_MAX, index;
	if(startblock==endblock){
		for(int k=i;k<=j;k++){
			if(lev[k]<mn){
				mn=lev[k];
				index=k;
			}
		}
		return index;
	}
	for(int k = i; k <= (startblock + 1)*len - 1; k++)if(lev[k]<mn){
				mn=lev[k];
				index=k;
			}
	for(int k=k = startblock + 1; k <= endblock - 1; k++)if(lev[b[k]]<mn){
			mn=lev[b[k]];
			index=b[k];
			}
	for(int k = endblock*len; k <= j; k++)if(lev[k]<mn){
				mn=lev[k];
				index=k;
			}
	return index;
}
void clear(){
	b.clear();
	euler.clear();
	lev.clear();
	for(int i=0;i<MAXN;i++){
		v[i].clear();
		first_occur[i].clear();
	}
}
int main(){
	int t;
	scanf("%d",&t);
	for(int tc=1;tc<=t;tc++){
		printf("Case %d:\n",tc);
		clear();
		int n,m,num;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&m);
			while(m--){
				scanf("%d",&num);
				v[i].push_back(num);
			}
		}
		dfs(1,0);
		sqrt_decompose();	
		int q;
		scanf("%d",&q);
		int v1,v2,l=0,r=0;
		while(q--){
			scanf("%d%d",&v1,&v2);
			l=first_occur[v1][0];
			r=first_occur[v2][0];
			if(l>r)swap(l,r);
			l--,r--;
			printf("%d\n",euler[query(l,r)]);
		}
	}
} 
