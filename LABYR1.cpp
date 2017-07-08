#include "bits/stdc++.h"
using namespace std;
int r, c;
char arr[1005][1005];
char visit[1005][1005];
pair<int, int>last;
int len;
const int dx[] = { 0,0,1,-1 };
const int dy[] = { 1,-1,0,0 };
bool isSafe(int i, int j)
{
	return (i >= 0) && (j >= 0) && (i < r) && (j < c);
}
void dfs(int i,int j,int l)
{
	visit[i][j] = 1;
	if (l > len)
	{
		last = make_pair(i, j);
		len = l;
	}
	for (int k = 0; k < 4; k++)
	{
		if (i + dx[k]>=0&& j + dy[k]>=0&& i + dx[k]<r&& j + dy[k] <c && (visit[i + dx[k]][j + dy[k]]==0) && arr[i + dx[k]][j + dy[k]] == '.')
		{
			dfs(i + dx[k], j + dy[k], l + 1);
		}
	}
}
int main()
{
	//READ;
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &c, &r);
		for (int i = 0; i < r; i++)
		{
			scanf("%s", arr[i]);
		}
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (arr[i][j] == '.')
				{
					//printf("%d %d\n", i, j);
					memset(visit, 0, sizeof(visit));
					len = -1;
					dfs(i, j, 0);
					memset(visit, 0, sizeof(visit));
					len = -1;
					//printf("%d %d\n", last.first, last.second);
					dfs(last.first, last.second, 0);
					printf("Maximum rope length is %d.\n", len);
					goto bnsl;
				}
			}
		}
	bnsl:;
	}
	return 0;
}  
