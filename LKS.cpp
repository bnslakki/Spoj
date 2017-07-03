#include "bits/stdc++.h"
using namespace std;
int dp[2][2000003];
int solve(int wt[], int val[], int capacity, int n)
{
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
	return dp[1][capacity];
}
int cost[502];
int fun[502];
int main()
{
	//READ;
	int k, n;
	scanf("%d%d", &k, &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &fun[i], &cost[i]);
	}
	printf("%d\n",solve(cost,fun,k,n));
}  
