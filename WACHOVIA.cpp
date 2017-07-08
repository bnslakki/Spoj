#include "bits/stdc++.h"
using namespace std;
int dp[2][1002];
int solve(int wt[], int val[], int capacity, int n)
{
	for(int i=0;i<2;i++)
	  for(int j=0;j<1002;j++)
	     dp[i][j]=0;
	for (int i = 1; i <= capacity; i++)
	{
		if (i >= wt[0])dp[0][i] = val[0];
	}
	for (int i = 1; i < n; i++)
	{	
		for (int j = 1; j <= capacity; j++)
		{
			if (j >= wt[i])
			{
				dp[1][j] = max(dp[0][j], val[i] + dp[0][j - wt[i]]);
			}
			else
			{
				dp[1][j] = dp[0][j];	
			}
		}
		for(int k=1;k<=capacity;k++)
		{
			dp[0][k]=dp[1][k];
		}
	}
	return dp[0][capacity];
}
int cost[52];
int val[52];
int main()
{
	//READ;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int k, n;
		scanf("%d%d", &k, &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &cost[i], &val[i]);
		}
		printf("Hey stupid robber, you can get %d.\n",solve(cost,val,k,n));
	}
}  
