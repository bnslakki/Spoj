#include "bits/stdc++.h"
using namespace std;
map<int, int>bf;
map<int, int>fof;
int arr[1000000];
int main()
{
//	INPUT;
	int n;
	int k = 0;
	int ans = 0;
	scanf("%d", &n);
	while (n--)
	{
		int a;
		scanf("%d", &a);
		bf[a] = 1;
		int m;
		scanf("%d", &m);
		while (m--)
		{
			int s;
			scanf("%d", &s);
			arr[k] = s;
			k++;
		}
	}
	for (int i = 0; i < k; i++)
	{
		if (bf[arr[i]] == 0)
		{
			if (fof[arr[i]] == 0)
			{
				ans++;
				fof[arr[i]] = 1;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
} 
