// KSUM
#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<malloc.h>
using namespace std;
struct mydata
{
	int ans;
	int best;
};
mydata segtree[4*100000];
mydata make_leaf(int val)
{
	mydata tempq;
	tempq.ans=val;
	tempq.best=val;
	return tempq;
}
mydata combine(mydata a,mydata b)
{
	int temp1,temp2,temp3;
	mydata temp;
	temp1=a.best+b.best;
	temp2=a.ans;
	temp3=b.ans;
	temp.ans=max(max(temp1,temp2),temp3);
	temp.best=max(a.best,b.best);
	return temp;
}
void buildtree(int arr[],int low,int high,int pos)
{
	if(low==high)
	{
		segtree[pos]=make_leaf(arr[low]);
        return;
	}
	int mid=(low+high)/2;
	buildtree(arr,low,mid,2*pos+1);
	buildtree(arr,mid+1,high,2*pos+2);
	segtree[pos]=combine(segtree[2*pos+1],segtree[2*pos+2]);
}
mydata range_query(int qlow,int qhigh,int low,int high,int pos)
{
	if(qlow==low&&qhigh==high)
	return segtree[pos];
	int mid=(low+high)/2;
	if(qhigh<=mid)
	return range_query(qlow,qhigh,low,mid,pos*2+1);
	if(qlow>mid)
	return range_query(qlow,qhigh,mid+1,high,pos*2+2);
	return combine(range_query(qlow,mid,low,mid,pos*2+1),range_query(mid+1,qhigh,mid+1,high,pos*2+2));
}
void update(int v,int low,int high,int pos,int val)
{
	if(low==high)
	segtree[v]=make_leaf(val);
	else
	{
		int mid=(low+high)/2;
		if(pos<=mid)
		update(2*v+1,low,mid,pos,val);
		else
		update(2*v+2,mid+1,high,pos,val);
		segtree[v]=combine(segtree[2*v+1],segtree[2*v+2]);
	}
}
int main()
{
//	freopen("t.txt","r",stdin);
	int n;
	scanf("%d",&n);
	int arr[n+4];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	buildtree(arr,0,n-1,0);
	int m;
	scanf("%d",&m);
	while(m--)
	{
		char ch[3];
		int x,y;
		scanf("%s",ch);
		scanf("%d%d",&x,&y);
	//	printf("%s %d %d\n",ch,x,y);
		if(ch[0]=='Q')
		{
			printf("%d\n",range_query(x-1,y-1,0,n-1,0).ans);
		}
		else if(ch[0]=='U')
		{
			update(0,0,n-1,x-1,y);
		}
	}
	return 0;
} 
