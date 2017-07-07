#include<bits/stdc++.h>

using namespace std;
int s[50];
vector<int>dp(1000009, -1);
void pre()
{
	for (int i = 1; i <= 48; i++)
	{
		s[i] = i*i*i;
	}
}
int solve(int n)
{
	if (n == 0)
		return 0;
	if (dp[n] != -1)
		return dp[n];
	int mn = 1000000;
	for (int i = 1;i<=47; i++)
	{
		if (n - s[i]<0)
			break;
		mn = min(mn, solve(n - s[i]));
	}
	dp[n] = mn + 1;
	return dp[n];
}
int main()
{
	pre();
//	INPUT;
	int n;
	int test = 1;
	while (scanf("%d", &n) != EOF)
	{
		//printf("%d\n", dp[n]);
		printf("Case #%d: %d\n", test, solve(n));
		test++;
	}
	return 0;
}
 
