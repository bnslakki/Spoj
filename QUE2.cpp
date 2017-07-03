#include "bits/stdc++.h"
using namespace std;
 
const int maxn=10005;
 
pair<int,int>arr[maxn],ans[maxn];
int bit[maxn];
int sum(int order) {
    int result=0;
    for(int i=order;i>0;i-=i&-i){
        result+=bit[i];
    }
    return result;
}
void update(int order,int n){
    for(int i=order;i<=n;i+=i&-i){
        bit[i]--;
    }
}
int binarySearch(int order, int begin, int end){
	if(begin == end) return begin;
    if(begin+1 == end) return sum(begin) >= order ? begin : end;
    int mid = begin + (end - begin >> 1);
    int midResult = sum(mid);
    if(midResult >= order) return binarySearch(order, begin, mid);
    else return binarySearch(order, mid + 1, end);
}
int main(){
	//freopen("t.txt","r",stdin);
	int t,n;
	auto cmp=[](pair<int,int>a,pair<int,int>b){
		if(a.first==b.first)return a.second>b.second;
		return a.first<b.first;
	};
	for(scanf("%d",&t);t--;){
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%d",&arr[i].first);
		for(int i=0;i<n;i++)scanf("%d",&arr[i].second),bit[i+1]=(i+1)&-(i+1);
		sort(arr,arr+n,cmp);
		
		for(int i=0;i<n;i++){
			int pos=binarySearch(arr[i].second+1,1,n+1);
			ans[pos-1]=arr[i];
			update(pos,n);
		}
		for(int i=0;i<n;i++){
			printf("%d ",ans[i].first);
		}
		printf("\n");
	}
} 
