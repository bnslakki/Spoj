#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,d;
	while(scanf("%d%d",&a,&d))
	{
		if(a==0&&d==0)
		{
			break;
		}
		int arr[a+2],arr2[d+2];
	int min=100000;
	for(int i=0;i<a;i++)
	{
		scanf("%d",&arr[i]);
		if(arr[i]<=min)
		{
			min=arr[i];
		}
	}
	for(int i=0;i<d;i++)
	{
		scanf("%d",&arr2[i]);
	}
	sort(arr2,arr2+d);
	if(arr2[0]<=min&&arr2[1]<=min)
	{
		printf("N\n");
	}
	else
	printf("Y\n");
	}
	
	return 0;
	
}
 
