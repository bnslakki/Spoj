#include<bits/stdc++.h>
using namespace std;
int ans[500];
int mul(int sz,int num)
{
	int carry=0;
	for(int i=0;i<sz;i++)
	{
		int t=ans[i]*num+carry;
		ans[i]=t%10;
		carry=t/10;
	}
	while(carry)
	{
		ans[sz]=carry%10;
		carry=carry/10;
		sz++;
	}
	return sz;
}
void fact(int n)
{
	ans[0]=1;
	int sz=1;
	for(int i=2;i<=n;i++)
	{
		sz=mul(sz,i);
	}
	for(int i=sz-1;i>=0;i--)printf("%d",ans[i]);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		fact(n);
		printf("\n");
	}
	return 0;
} 
