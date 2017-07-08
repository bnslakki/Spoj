#include<bits/stdc++.h>
using namespace std;
int arr[100005];
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<q;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		if(!(r-l))printf("%d\n",arr[l-1]);
		else printf("0\n");
	}
	return 0;
} 
