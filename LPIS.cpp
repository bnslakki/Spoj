#include "bits/stdc++.h"
using namespace std;
vector<stack<int> >s(1000005);
int add[1000005];
int arr[1000005];
int main()
{
	//READ;
	int n;
	scanf("%d", &n);
	int mx = -1;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		if (arr[i] >= mx)
		{
			mx = arr[i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (add[arr[i] - 1] != 0)
		{
			if (s[add[arr[i] - 1]].top() == arr[i] - 1)
			{
				s[add[arr[i] - 1]].push(arr[i]);
				add[arr[i]] = add[arr[i] - 1];
			}
		}
		else
		{
			if (add[arr[i]] == 0)
			{
				s[arr[i]].push(arr[i]);
				add[arr[i]] = arr[i];
			}
		}
	}
	int ans = -1;
	for (int i = 1; i <= mx; i++)
	{
		int t = s[i].size();
		if (t >= ans)
		{
			ans = t;
		}
		//printf("%d\n", s[i].size());
	}
 
 
	printf("%d\n",ans);
	return 0;
} 
