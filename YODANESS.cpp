#include "bits/stdc++.h"
using namespace std;
 
unordered_map<string,int>mp;
int arr[30003];
int n;
int bit[30003];
 
int sum(int i){
	int ret=0;
	while(i){
		ret+=bit[i];
		i-=i&-i;
	}
	return ret;
}
void update(int i){
	while(i<=n){
		bit[i]+=1;
		i+=i&-i;
	}
}
 
int inverse_count(){
	int ret=0;
	for(int i=n-1;i>=0;i--){
		ret+=sum(arr[i]);
		update(arr[i]+1);
	}
	return ret;
}
 
int main(){
	int t;
	string s;
	for(scanf("%d",&t);t--;){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			cin>>s;
			mp[s]=i;
		}
		for(int i=1;i<=n;i++){
			cin>>s;
			arr[i-1]=mp[s];
		}
		printf("%d\n",inverse_count());
		mp.clear();
		memset(bit,0,sizeof bit);
	}
} 
