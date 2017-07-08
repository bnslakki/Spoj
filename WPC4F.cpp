#include "bits/stdc++.h"
using namespace std;
class WPC4F
{
public:
	WPC4F(int n, int m);
	~WPC4F() {}
	int no_of_stone(int arr[][105], int n, int m);
private:
	int dp[105][105];
};
 
WPC4F::WPC4F(int n, int m)
{
	for (size_t i = 0; i <= n + 1; i++)
	{
		dp[i][0] = 10000000;
		dp[i][m + 1] = 10000000;
	}
	for (size_t i = 0; i <= n + 1; i++)
	{
		for (size_t j = 1; j < m + 1; j++)
		{
			dp[i][j] = 0;
			//cout << dp[i][j]<<" ";
		}
	}
}
int WPC4F::no_of_stone(int arr[][105], int n, int m)
{
	for (size_t i = 0; i < m; i++)
	{
 
		dp[0][i + 1] = arr[0][i];
	}
	for (size_t i = 1; i < n; i++)
	{
		dp[i][1] += min(dp[i - 1][2], dp[i - 1][3]) + arr[i][0];
		dp[i][2] += min(dp[i - 1][1], dp[i - 1][3]) + arr[i][1];
		dp[i][3] += min(dp[i - 1][1], dp[i - 1][2]) + arr[i][2];
	}
 
	int mn = 10000000;
	for (size_t j = 1; j <= m; j++)
	{
		if (dp[n - 1][j] <= mn)
		{
			mn = dp[n - 1][j];
		}
		//printf("%d ", dp[n-1][j]);
	}
	return mn;
}
int arr[105][105];
int main()
{
//	INPUT;
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < 3; j++)
			{
				scanf("%d", &arr[i][j]);
			}
		}
		WPC4F ans(n, 3);
		printf("%d\n", ans.no_of_stone(arr, n, 3));
	}
} 
