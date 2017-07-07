#include<bits/stdc++.h>
#define ll long long
int main()
{
//	freopen("t.txt","r",stdin);
	int n;
	scanf("%d",&n);
	ll arr[n+3]; 
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&arr[i]);
	}
	ll temp=arr[0];
	ll temp2=~arr[0];
	for(int i=1;i<n;i++)
	{
		temp|=arr[i];
		temp2|=~arr[i];
	}
	printf("%lld\n",temp&temp2);
} 
