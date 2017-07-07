#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
int bit[1000007];
int getnext(int index)
{
	return index+(index&(-index));
}
void updatetree(int val,int index,int n)
{
	int l=index;
	while(l<=n)
	{
		bit[l]+=val;
		l=getnext(l);
	}
}
int getparent(int index)
{
	return index-(index&(-index));
}
int sum(int index)
{
	index++;
	int sum=0;
	while(index>0)
	{
		sum+=bit[index];
		index=getparent(index);
	}
	return sum;
}
int main()
{
//	freopen("t.txt","r",stdin);
	int n,q;
	scanf("%d%d",&n,&q);
	while(q--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		updatetree(1,a,n);
		updatetree(-1,b+1,n);
	}
	int arr[n+3];
	int k=0;
	for(int i=1;i<=n;i++)
	{
		arr[k]=sum(i);
		k++;
	}
	sort(arr,arr+k);
	printf("%d\n",arr[n/2]);
} 
