#include<bits/stdc++.h>
int hs[1005];
int main()
{
//	freopen("t.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		for(int i=0;i<1003;i++)
		hs[i]=0;
		int n;
		scanf("%d",&n);
		int arr[n+3];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			hs[arr[i]]++;
		}
		if(n==2)
		{
			if(arr[0]==1&&arr[1]==1)
			{
				printf("YES\n");
			}
			else
			printf("NO\n");
		}
		else
		{
		if(n%2==0)
		{
			bool flag=false;
			if(hs[n-1]==2)
			{
				for(int i=1;i<=n-2;i++)
				{
					if(hs[i]==1||hs[i]==2)
					{
						//printf("fd");
						if(hs[i]==1)
						{
							if(hs[n-1-i]!=1)
							{
								flag=true;
								printf("NO\n");
								break;
							}
						}
						else if(hs[i]==2)
						{
						//	printf("fd");
							if(hs[n-1-i]!=0)
							{
							//	printf("fd");
								flag=true;
								printf("NO\n");
								break;
							}
						}
					}
				}
				if(!flag)
				printf("YES\n");
			}
			else
			printf("NO\n");
		}
		else
		{
			bool flag=false;
			int mid=n/2;
			if(hs[n-1]==2&&hs[mid]==1)
			{
				for(int i=1;i<=n-2;i++)
				{
					if(hs[i]==1||hs[i]==2)
					{
						if(hs[i]==1)
						{
							if(hs[n-1-i]!=1)
							{
								flag=true;
								printf("NO\n");
								break;
							}
						}
						else if(hs[i]==2)
						{
							if(hs[n-1-i]!=0)
							{
								flag=true;
								printf("NO\n");
								break;
							}
						}
					}
				}
				if(flag==false)
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
	}
	}
	
