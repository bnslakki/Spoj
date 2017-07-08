#include<bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("t.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		int count=0;
		scanf("%d%d",&n,&k);
		int arr[n+3],temp[n+3];
		
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		sort(arr,arr+n);
		vector<int> v(arr,arr+n);
		for(int i=0;i<n;i++)
		{
			temp[i]=k-arr[i];
	//		printf("%d ",temp[i]);
		}
		
		for(int i=0;i<n;i++)
		{
			if(binary_search(v.begin(),v.end(),temp[i]))
			{
				count++;
			}
		}
		printf("%d\n",count/2);
	}
	return 0;
} 
